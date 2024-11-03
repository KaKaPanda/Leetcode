class Solution {
public:
    int findMin(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return INT_MIN;

        int left = 0, right = sz-1;
        while (left + 1 < right) {
            if (nums[left] < nums[right]) return nums[left]; // 直接返回左边最小值

            int mid = (left + right) / 2;

            if (nums[left] < nums[mid]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return min(nums[left], nums[right]);
    }
};