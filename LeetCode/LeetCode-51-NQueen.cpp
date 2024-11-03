class Solution {
public:
    bool checkConflict(const vector<pair<int, int>>& queens, int i, int j) { // 记录已放置皇后的位置，通过坐标判断是否有冲突, 时间复杂度: N!
        for (auto &queen : queens) {
            if (queen.first == i || queen.second == j) {
                return true;
            }
            if (abs(queen.first - i) == abs(queen.second - j)) {
                return true;
            }
        }
        return false;
    }

    void subSolveNQueens(vector<string>& matrix, vector<pair<int, int>>& queens, int row) {
        if (queens.size() == matrix.size()) {
            res.push_back(matrix);
            return;
        }

        for (int j = 0; j < matrix.size(); ++j) {  // 这里固定第n个皇后只能放在第row行
            if (checkConflict(queens, row, j)) continue;
            matrix[row][j] = 'Q';
            queens.push_back(pair<int, int>(row, j));
            subSolveNQueens(matrix, queens, row+1);
            matrix[row][j] = '.';
            queens.pop_back();
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n == 0) return res;
        
        vector<string> matrix = vector<string>(n, string(n, '.'));
        vector<pair<int, int>> queens = vector<pair<int, int>>();
        subSolveNQueens(matrix, queens, 0);
        return res;
    }

    vector<vector<string>> res;
};