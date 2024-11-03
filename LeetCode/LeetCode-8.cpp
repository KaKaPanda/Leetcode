class Solution {
public:
    string state = "start";//0:空格,1:符号,2数字:,3:结尾
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "number", "end"}},
        {"signed", {"end", "end", "number", "end"}},
        {"number", {"end", "end", "number", "end"}} };
    long long ans = 0, sign = 1, prefix = INT_MAX;
    int checkChar(const char &c) {
        if (c == ' ') return 0;
        if (c == '+' || c == '-') {
            if (state == "start") sign = (c == '+')? 1 : -1;
            return 1;
        }
        if (c >= '0' && c <= '9') {
            ans = ans * 10 + (c - '0');
            if (sign == 1 && ans >= prefix) {
                ans = prefix;
                return 3;
            }
            if (sign == -1 && ans >= prefix + 1) {
                ans = prefix + 1;
                return 3;
            }
            return 2;
        }
        return 3;
    }
    int myAtoi(string str) {
        for(auto &c : str){
            state = table[state][checkChar(c)];
            if(state == "end") break;
        }
        return sign * ans;
    }
};