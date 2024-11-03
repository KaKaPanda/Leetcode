class Solution {
public:
    // 时间复杂度O(n)，空间复杂度O(n)
    int largestRectangleArea(vector<int>& heights) { // [2, 4, 6, 80, 100, 12]
        int largest_area = 0;
        std::stack<int> index_stk; // 需要用栈来记录的递增高度的索引
        
        heights.push_back(INT_MIN); // 这里写入 INT_MIN 来保证 index_stk 先前所有元素都会被推出
        
        for (int i = 0; i < heights.size(); ++i) {
            while(!index_stk.empty() && heights[index_stk.top()] >= heights[i]) {
                int height = heights[index_stk.top()]; // 高度为被推出索引高度
                index_stk.pop(); // 这里先推出元素来拿前一个元素
                int width = i - (index_stk.empty() ? 0 : index_stk.top()+1); // 宽度要拉到前一个元素的下一个索引
                int area = width * height;
                largest_area = max(largest_area, area);
            }
            index_stk.push(i); // 注意这里要推入的是索引
        }

        return largest_area;
    }
};