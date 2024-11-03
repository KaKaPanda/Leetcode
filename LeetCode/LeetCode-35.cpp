class Solution {
public:
    int searchInsert(vector<int>& nums, int target) { // nums为无重复元素的升序排列数组
        if (nums.size() == 0 || target <= nums[0]) return 0;
        if (target > nums[nums.size() - 1]) return nums.size();

        int left = 0, right = nums.size();
        while (left + 1 != right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right; // 搜索不到，返回right作为插入位置索引
    }
};