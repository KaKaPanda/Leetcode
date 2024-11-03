class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; ++i) { // 进行对角翻转
            for (int j = i+1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; ++i) { // 进行左右翻转
            for (int j = 0; j < n/2; ++j) {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
        return;
    }
};