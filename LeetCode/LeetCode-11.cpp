class Solution {
public:
    int minComp(int a, int b) {
        return a < b ? a : b;
    }
    int maxArea(vector<int>& height) { // 接雨水
        if (height.size() <= 1) {
            return 0;
        }

        int p_left = 0;
        int p_right = height.size() - 1;
        int res = 0;
        
        while(p_left < p_right) { // 双指针法
            int temp = (p_right - p_left) * minComp(height[p_left], height[p_right]);
            if (temp > res) {
                res = temp;
            }

            if (height[p_left] < height[p_right]) { // 移动较小端的指针
                ++p_left;
            } else {
                --p_right;
            }
        }
        return res;
    }
};