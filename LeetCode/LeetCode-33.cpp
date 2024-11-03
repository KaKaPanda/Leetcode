class Solution {
public:
    int search(vector<int>& nums, int target) { // 整数数组 nums 按升序排列，数组中的值 互不相同
        if (nums.size() == 0) return -1;
        if (nums.size() == 1 && nums[0] != target) return -1;  // 长度小于1特殊处理

        int left = 0, right = nums.size()-1;
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;

        while (left + 1 != right) { // 注意循环退出条件
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] > nums[left]) { // 中点落在左半边
                if (nums[mid] > target && nums[left] < target) {
                    right = mid; // target落在左上半部分, 更新right
                } else {
                    left = mid;
                }
            } else { // 中点落在右半边
                if (nums[mid] < target && nums[right] > target) {
                    left = mid;  // target落在右下半部分, 更新left
                } else {
                    right = mid;
                }
            }
        }
        return -1;
    }
};