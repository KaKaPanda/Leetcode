class Solution {
private:
    int subFindMin(vector<int>& nums, int left, int right) {
        while (left + 1 < right) {
            if (nums[left] < nums[right]) return nums[left];  // 直接返回左边最小值

            int mid = (left + right) / 2;

            if (nums[left] == nums[right]) {
                if (nums[left] == nums[mid]) {
                    return min(subFindMin(nums, left, mid), subFindMin(nums, mid+1, right)); // 没法判断则递归查找
                } else if (nums[left] < nums[mid]) {
                    left = mid;
                } else {
                    right = mid;
                }
            } else { // left > right
                if (nums[left] <= nums[mid]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
        }
        return min(nums[left], nums[right]);
    }

public:
    int findMin(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return INT_MIN;

        return subFindMin(nums, 0, sz - 1);
    }
};