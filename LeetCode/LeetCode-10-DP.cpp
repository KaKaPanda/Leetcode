class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size() + 1, m = p.size() + 1;
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(m, 0));
        dp[0][0] = true; // 空串可以匹配空模式

        // lambda 表达式
        auto matches = [&](int i, int j)->bool{
            if (i == 0) return false;
            if (p[j-1] == '.') return true;
            return s[i-1] == p[j-1];
        };

        for(int i = 0; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                if (p[j-1] == '*') { // 通配符特殊处理
                    if (j >= 2) {
                        dp[i][j] |= dp[i][j-2]; // 一个字符都不匹配
                    }
                    if (matches(i, j-1)) { // 当前字符与通配符前一个字符匹配
                        dp[i][j] |= dp[i-1][j];
                    }
                } else if (matches(i, j)) {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }

        return dp[n-1][m-1]; // 注意索引不要越界
    }
};