class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;

        if (target < matrix[0][0] || target > matrix[n-1][m-1]) return false;
        if (target == matrix[0][0] || target == matrix[n-1][m-1]) return true;

        int left = 0, right = n*m;
        while (left+1 != right) {
            int mid = (left + right) / 2;
            int row = mid / m;
            int col = mid % m;
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) { // 更新左索引
                left = mid;
            } else if (matrix[row][col] > target) { // 更新右索引
                right = mid;
            }
        }
        return false;
    }
};