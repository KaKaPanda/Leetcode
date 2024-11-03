class Solution {
public:
    bool checkConflict(const vector<pair<int, int>>& queens, int row, int col) { // 记录已放置皇后的位置，通过坐标判断是否有冲突, 时间复杂度: N!
        for (auto & queen : queens) {
            if (queen.first == row || queen.second == col) {
                return true;
            } else if (abs(queen.first - row) == abs(queen.second - col)) {
                return true;
            }
        }
        return false;
    }

    void setNQueens(vector<pair<int, int>>& queens, int n) {
        if (queens.size() == n) {
            ++solutions;
            return;
        }

        int row = queens.size(); // 这里固定第n个皇后只能放在第row行
        for (int col = 0; col < n; ++col) {
            if (checkConflict(queens, row, col)) continue;

            queens.push_back(pair<int, int>(row, col));
            setNQueens(queens, n);
            queens.pop_back();
        }
        return;
    }


    int totalNQueens(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        vector<pair<int, int>> queens;
        setNQueens(queens, n);
        return solutions;
    }

    int solutions = 0;
};