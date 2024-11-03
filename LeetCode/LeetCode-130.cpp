class Solution {
private:
    void bfs(vector<vector<char>>& board, vector<pair<int, int>>& locations) {
        int n = board.size(), m = board[0].size();
        while (!locations.empty()) {
            vector<pair<int, int>> next_locations;
            for (int i = 0; i < locations.size(); ++i) {
                int pos_i = locations[i].first;
                int pos_j = locations[i].second;
                if (pos_i-1 >= 0 && board[pos_i-1][pos_j] == '0') {
                    board[pos_i-1][pos_j] = 'O';
                    next_locations.emplace_back(pair<int, int>{pos_i-1, pos_j});
                }
                if (pos_i+1 < n && board[pos_i+1][pos_j] == '0') {
                    board[pos_i+1][pos_j] = 'O';
                    next_locations.emplace_back(pair<int, int>{pos_i+1, pos_j});
                }
                if (pos_j-1 >= 0 && board[pos_i][pos_j-1] == '0') {
                    board[pos_i][pos_j-1] = 'O';
                    next_locations.emplace_back(pair<int, int>{pos_i, pos_j-1});
                }
                if (pos_j+1 < m && board[pos_i][pos_j+1] == '0') {
                    board[pos_i][pos_j+1] = 'O';
                    next_locations.emplace_back(pair<int, int>{pos_i, pos_j+1});
                }
            }
            locations = next_locations;
        }
    }

public:
    void solve(vector<vector<char>>& board) { // bfs
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        if (m == 0) return;

        vector<pair<int, int>> locations;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                        locations.emplace_back(pair<int, int>{i, j});
                    } else {
                        board[i][j] = '0'; // 先换成其他符号
                    }
                }
            }
        }

        bfs(board, locations); // 从边缘向内扩散
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == '0') {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};