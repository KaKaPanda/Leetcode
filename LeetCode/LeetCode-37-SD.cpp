class Solution {
public:
    vector<bitset<9>> rowSet;
    vector<bitset<9>> colSet;
    vector<vector<bitset<9>>> celSet;

    bitset<9> getStatus(int row, int col) {
        return (rowSet[row] | colSet[col] | celSet[row/3][col/3]);
    }

    vector<int> findNext(const vector<vector<char>>& board) { // 找到不确定性最小的格子进行递归，否则会超时
        vector<int> next;
        int maxStatus = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    continue;
                }
                bitset<9> status = getStatus(i, j);
                if (status.count() >= maxStatus) { // 注意这里会有数值类型转换
                    maxStatus = status.count();
                    next = {i, j};
                }
            }
        }
        return next;
    }

    bool dfs(vector<vector<char>>& board, int dotCnt) {
        if (dotCnt == 0) return true;

        vector<int> next = findNext(board);
        if (next.size() != 2) return false;
        int row = next[0], col = next[1];
        
        bitset<9> status = getStatus(row, col);
        if (status.count() == 9) {
            return false;
        }

        for (int k = 0; k < 9; ++k) {
            if (status.test(k)) {
                continue;
            }
            int mask = (1 << k);

            board[row][col] = '1' + k;
            rowSet[row] |= mask;
            colSet[col] |= mask;
            celSet[row/3][col/3] |= mask;
            if (dfs(board, dotCnt-1)) {
                return true;
            }
            board[row][col] = '.';
            rowSet[row] ^= mask;
            colSet[col] ^= mask;
            celSet[row/3][col/3] ^= mask;
        }
            
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9) return;

        rowSet = vector<bitset<9>>(9, bitset<9>());
        colSet = vector<bitset<9>>(9, bitset<9>());
        celSet = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

        int dotCnt = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    ++dotCnt;
                } else {
                    int number = board[i][j] - '1';
                    rowSet[i] |= (1 << number);
                    colSet[j] |= (1 << number);
                    celSet[i/3][j/3] |= (1 << number); 
                }
            }
        }
        dfs(board, dotCnt);
    }
};