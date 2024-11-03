class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        int n = matrix.size();
        if (n == 0) return res;
        int m = matrix[0].size();
        if (m == 0) return res;

        int state = 0;
        int up = 0, down = n, left = 0, right = m;
        while (up != down && left != right) {
            if (state == 0) {
                for (int i = up, j = left; j < right; ++j) {
                    res.push_back(matrix[i][j]);
                }
                ++up;
            } else if (state == 1) {
                for (int i = up, j = right - 1; i < down; ++i) {
                    res.push_back(matrix[i][j]);
                }
                --right;
            } else if (state == 2) {
                for (int i = down - 1, j = right - 1; j >= left; --j) {
                    res.push_back(matrix[i][j]);
                }
                --down;
            } else if (state == 3) {
                for (int i = down - 1, j = left; i >= up; --i) {
                    res.push_back(matrix[i][j]);
                }
                ++left;
            }
            state = (state + 1) % 4;
        }
        return res;
    }
};