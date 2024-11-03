class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        if (n != 9) return false;
        int m = board[0].size();
        if (m != 9) return false;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == '.') continue;

                for (int ii = i + 1; ii < n; ++ii) {  // 只需要对比后续元素
                    if (board[ii][j] == board[i][j]) {
                        return false;
                    }
                }
                for (int jj = j + 1; jj < m; ++jj) {
                    if (board[i][jj] == board[i][j]) {
                        return false;
                    }
                }

                int nn = (i/3 + 1) * 3, mm = (j/3 + 1) * 3;
                for (int ii = nn-3; ii < nn; ++ii) { // 九宫格这里要注意便利范围
                    for (int jj = mm-3; jj < mm; ++jj) {
                        if (ii == i || jj == j) continue;
                        if (board[ii][jj] == board[i][j]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};