class Solution {
public:
    string convertToTitle(int columnNumber) {
        if (columnNumber <= 0) return "";

        string ans;
        while (columnNumber != 0) {
            char num = (columnNumber - 1) % 26 + 'A';
            ans += num;
            columnNumber = (columnNumber - 1) / 26; // 注意这里要先减1
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};