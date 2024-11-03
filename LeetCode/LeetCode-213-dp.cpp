class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0]; // 只有一家

        int ans = 0, preMax = 0, curMax = 0;
        for (int i = 0; i < nums.size()-1; ++i) { // 忽略最后一家
            int nexMax = max(curMax, preMax + nums[i]);
            preMax = curMax;
            curMax = nexMax;
        }
        ans = curMax;

        preMax = 0, curMax = 0;
        for (int i = 1; i < nums.size(); ++i) { // 忽略第一家
            int nexMax = max(curMax, preMax + nums[i]);
            preMax = curMax;
            curMax = nexMax;
        }
        ans = max(ans, curMax); // 取较大值
        return ans;
    }
};