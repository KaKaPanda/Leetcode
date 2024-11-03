class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size() + 1, m = p.size() + 1;
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(m, 0));

        dp[0][0] = true;

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (p[j-1] == '*') {
                    for (int k = 0; k <= i; ++k) {
                        dp[i][j] |= dp[i-k][j-1];
                    }
                } else if (i > 0 && (p[j-1] == '?' || s[i-1] == p[j-1])) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    ; // do nothing
                }
            }
        }

        return dp[n-1][m-1];
    }
};