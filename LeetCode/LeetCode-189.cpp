class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        k %= sz; // 先取余数
        if (sz == 0 || k == 0) return;

        // 每个元素做两次镜像翻转
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());

        // for (int i = 0; i < k; ++i) { // 每次循环移动一个数, 该方法会超时
        //     int temp = nums[sz - k + i];
        //     for (int j = sz - k + i; j > i; --j) {
        //         nums[j] = nums[j - 1];
        //     }
        //     nums[i] = temp;
        // }
    }
};