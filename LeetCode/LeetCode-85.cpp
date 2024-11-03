class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;

        int largest_area = 0;
        vector<int> heights = vector<int>(m+1, 0); // //建议不要在原数组上进行累加修改，因为矩阵的维度有可能会超过char的范围
        heights[m] = INT_MIN;  // 这里写入 INT_MIN 来保证 index_stk 先前所有元素都会被推出

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0; // 当前行等于0则清空数值
                } else {
                    heights[j] += 1;
                }
            }

            std::stack<int> index_stk;

            for (int j = 0; j < heights.size(); ++j) {
                while (!index_stk.empty() && heights[index_stk.top()] >= heights[j]) {
                    int height = heights[index_stk.top()]; // 高度为被推出索引高度
                    index_stk.pop();  // 这里先推出元素来拿前一个元素
                    int width = j - (index_stk.empty() ? 0 : index_stk.top()+1); // 宽度要拉到前一个元素的下一个索引
                    int area = height * width;
                    largest_area = max(largest_area, area);
                }

                index_stk.push(j); // 注意这里要推入的是索引
            }
        }
        return largest_area;
    }
};