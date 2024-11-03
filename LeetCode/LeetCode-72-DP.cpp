class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size() + 1;
        int m = word2.size() + 1;
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0) {
                    dp[i][j] = j;  // 矩阵边界
                    continue;
                } else if (j == 0) {
                    dp[i][j] = i;
                    continue;
                }
                int down = dp[i-1][j] + 1;
                int left = dp[i][j-1] + 1;
                int left_down = dp[i-1][j-1];
                if (word1[i-1] != word2[j-1]) { // 下一个字符不想等，距离加1
                    left_down += 1;
                }
                dp[i][j] = min(left, min(down, left_down));
            }
        }
        return dp[n-1][m-1];
    }
};