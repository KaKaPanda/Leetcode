class Solution {
public:
    bool sub_exist(vector<vector<char>>& board, string word, int count, int row, int col) {
        if (count == word.size()) return true;

        int n = board.size();
        if (n == 0) return false;
        int m = board[0].size();
        if (m == 0) return false;

        if (row - 1 >= 0 && board[row-1][col] == word[count]) { // 向上匹配
            int val = board[row-1][col];
            board[row-1][col] = 0;  // 代表这个位置被占用
            if (sub_exist(board, word, count+1, row-1, col) == true) {
                return true;
            }
            board[row-1][col] = val;  // 未匹配成功，恢复现场
        }

        if (row + 1 < n && board[row+1][col] == word[count]) { // 向下匹配
            int val = board[row+1][col];
            board[row+1][col] = 0;  // 代表这个位置被占用
            if (sub_exist(board, word, count+1, row+1, col) == true) {
                return true;
            }
            board[row+1][col] = val;  // 未匹配成功，恢复现场
        }

        if (col - 1 >= 0 && board[row][col-1] == word[count]) { // 向左匹配
            int val = board[row][col-1];
            board[row][col-1] = 0;  // 代表这个位置被占用
            if (sub_exist(board, word, count+1, row, col-1) == true) {
                return true;
            }
            board[row][col-1] = val;  // 未匹配成功，恢复现场
        }

        if (col + 1 < m && board[row][col+1] == word[count]) { // 向右匹配
            int val = board[row][col+1];
            board[row][col+1] = 0;  // 代表这个位置被占用
            if (sub_exist(board, word, count+1, row, col+1) == true) {
                return true;
            }
            board[row][col+1] = val;  // 未匹配成功，恢复现场
        }

        return false; // 表示四个方向都没有匹配
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) return true;

        int n = board.size();
        if (n == 0) return false;
        int m = board[0].size();
        if (m == 0) return false;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {  // 先匹配到第一个字符
                    int val = board[i][j];
                    board[i][j] = 0;
                    if (sub_exist(board, word, 1, i, j)) {
                        return true;
                    }
                    board[i][j] = val;
                }
            }
        }
        return false;
    }
};