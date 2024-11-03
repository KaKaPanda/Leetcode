class Solution {
public:
    int maxSubArray(vector<int>& nums) { // 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
        int max = INT_MIN, sum = 0;
        for (int i = 0; i < nums.size(); ) {
            if (max <= 0 && nums[i] <= 0) {
                if (nums[i] > max) {
                    max = nums[i]; // 结果可能为某个负数
                }
                ++i;
                continue;
            }

            while (i < nums.size() && nums[i] >= 0) { 
                sum += nums[i++];
            }

            int sub = 0;
            while (i < nums.size() && nums[i] < 0) {
                sub += nums[i++];
            }

            if (sum > max) {
                max = sum;
            }
            if (sum + sub > 0) {
                sum += sub; // 求和作为下一次累积初始值
            } else {
                sum = 0; // 清空
            }
        }
        return max;
    }
};