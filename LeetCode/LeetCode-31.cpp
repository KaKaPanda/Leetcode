class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;

        // 从右往左找到第一个a<b
        for (int i = nums.size()-1; i > 0; --i) {
            if (nums[i-1] < nums[i]) { 
                // 将大于num[i-1]的最小元素前置，剩余元素升序
                for (int j = nums.size()-1; j >= i; --j) {
                    if (nums[j] > nums[i-1]) {
                        swap(nums[i-1], nums[j]);
                        std::sort(nums.begin()+i, nums.end());
                        return;
                    }
                }
            }
        }

        std::sort(nums.begin(), nums.end());; // 全部反转
        return;
    }
};