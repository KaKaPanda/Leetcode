class Solution {
public:
    int rob(vector<int>& nums) {
        int preMax = 0, curMax = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int nexMax = max(curMax, preMax + nums[i]);
            preMax = curMax;
            curMax = nexMax;
        }
        return curMax;
    }
};