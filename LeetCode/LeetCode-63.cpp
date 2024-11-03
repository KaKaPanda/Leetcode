class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0) return 0;
        int m = obstacleGrid[0].size();
        if (m == 0) return 0;
        obstacleGrid[0][0] = !(obstacleGrid[0][0]); // 注意第一格是不是障碍


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i > 0 || j > 0) && obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                if (i > 0) {
                    obstacleGrid[i][j] += obstacleGrid[i-1][j];
                }
                if (j > 0) {
                    obstacleGrid[i][j] += obstacleGrid[i][j-1];
                }
            }
        }
        return obstacleGrid[n-1][m-1];
    }
};