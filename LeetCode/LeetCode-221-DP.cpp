class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) { // 注意 matrix 中存的是 char
        int n = matrix.size(), m = (n == 0) ? 0 : matrix[0].size();
        if (n == 0 || m == 0) return 0;

        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(m, 0));
        int max_square_len = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '0') continue;

                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1; // 注意要包含斜对角
                }
                max_square_len = max(max_square_len, dp[i][j]);
            }
        }

        return max_square_len * max_square_len;
    }
};