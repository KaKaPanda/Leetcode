class Solution {
public:
    // 如果按照从左上往右下的顺序进行动态规划，对于每一条路径，我们需要同时记录两个值。
    // 第一个是「从出发点到当前点的路径和」，第二个是「从出发点到当前点所需的最小初始值」。而这两个值的重要程度相同

    // 如果按照从左上往右下的顺序进行动态规划，我们无法直接确定到达的最优方案，
    // 因为有两个重要程度相同的参数同时影响后续的决策。也就是说，这样的动态规划是不满足「无后效性」的。

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        if (n == 0) return 1;
        int m = dungeon[0].size();
        if (m == 0) return 1;

        vector<vector<int>> dp = vector<vector<int>>(n+1, vector<int>(m+1, INT_MAX));
        dp[n][m-1] = dp[n-1][m] = 1;
        for (int i = n-1; i >= 0; --i) {
            for (int j = m-1; j >= 0; --j) {
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = max(dp[i][j], 1);
            }
        }

        return begHealth[0][0];
    }
};