class Solution {
public:
    int str2num(const string& s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            res = res * 10 + (s[i] - '0');
        }
        return res;
    }

    vector<string> subIpAddress(const string& s, int idx, int cnt) {
        vector<string> res;
        string dot = (idx == 0)? "" : ".";

        int remain_bits = s.size() - idx;
        if (remain_bits < cnt || remain_bits > 3*cnt) return res;

        if (cnt == 1) { // 剩余1个section
            if (remain_bits > 1 && s[idx] == '0') { // 排除多位数且前导为0
                return res;
            }
            string section = s.substr(idx, remain_bits);
            if (str2num(section) <= 255) {
                res.push_back(dot + section);
                return res;
            }
        }

        for (int i = idx; i < idx+3 && i < s.size(); ++i) { // 循环最多取3位
            string section = s.substr(idx, i-idx+1); // 注意这里截取的位数表达
            if (str2num(section) > 255) break;

            vector<string> sub_res = subIpAddress(s, i+1, cnt-1); // 注意这里下个迭代为i+1
            for (int i = 0; i < sub_res.size(); ++i) {
                res.push_back(dot + section + sub_res[i]);
            }
            if (s[idx] == '0') break; // 前导为0直接返回
        }

        return res;
    }

    vector<string> restoreIpAddresses(string s) {
        return subIpAddress(s, 0, 4);
    }
};