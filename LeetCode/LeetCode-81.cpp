class Solution {
public:
    bool search(vector<int>& nums, int target) {  // 整数数组 nums 按升序排列，数组中的值 不必互不相同，类似题目33
        if (nums.size() == 0) return false;       // 区别: 33题画图分析是一条单调的斜线，本题可能某个区间为水平线
        if (nums.size() == 1) return nums[0] == target;  // 长度小于1特殊处理

        int left = 0, right = nums.size()-1;
        if (nums[left] == target || nums[right] == target) return true;

        while (left + 1 != right) {  // 注意循环退出条件
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return true;
            }

            int mid_loc_side = 0; // 1 0 1 1 1
            if (nums[mid] == nums[left]) { // 不知道是落在左半边还是右半边，需要特殊处理，检查单调性
                for (int j = left+1; j <= mid; ++j) {
                    if (nums[j-1] > nums[j]) {
                        mid_loc_side = 1; // 说明中点落在右边
                        break;
                    }
                }
                if (mid_loc_side != 1) {
                    mid_loc_side = -1;
                }
            }

            if (nums[mid] > nums[left] || mid_loc_side == -1) {  // 中点落在左半边
                if (nums[left] < target && target < nums[mid]) {
                    right = mid;  // target落在左上半部分, 更新right
                } else {
                    left = mid;
                }
            } else if (nums[mid] < nums[left] || mid_loc_side == 1) {  // 中点落在右半边
                if (nums[right] > target && target > nums[mid]) {
                    left = mid;  // target落在右下半部分, 更新left
                } else {
                    right = mid;
                }
            }
        }
        return false;
    }
};
