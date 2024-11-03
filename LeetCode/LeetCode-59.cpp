class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int idx_i = 0, idx_j = 0;
        int state = 0; // 用状态来表示要走那条边
        int count = 1;
        vector<vector<int>> res(n, vector<int>(n, 0));
        while (count <= n*n) {  // 元素个数为 n*n
            if (state == 0) {
                while(idx_j < n && res[idx_i][idx_j] == 0) { // 判断元素为0才填充
                    res[idx_i][idx_j++] = count++;
                }
                --idx_j; // 注意需要调整两个索引
                ++idx_i;
                state = 1;
            } else if (state == 1) {
                while(idx_i < n && res[idx_i][idx_j] == 0) {
                    res[idx_i++][idx_j] = count++;
                }
                --idx_i;
                --idx_j;
                state = 2;
            } else if (state == 2) {
                while(idx_j >= 0 && res[idx_i][idx_j] == 0) {
                    res[idx_i][idx_j--] = count++;
                }
                ++idx_j;
                --idx_i;
                state = 3;
            } else if (state == 3) {
                while(idx_i >= 0 && res[idx_i][idx_j] == 0) {
                    res[idx_i--][idx_j] = count++;
                }
                ++idx_i;
                ++idx_j;
                state = 0;
            }
        }
        return res;
    }
};