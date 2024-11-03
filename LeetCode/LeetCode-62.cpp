class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mat = vector<vector<int>>(m, vector<int>(n));
        mat[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) mat[i][j] += mat[i-1][j];
                if (j > 0) mat[i][j] += mat[i][j-1];
            }
        }
        return mat[m-1][n-1];
    }
};