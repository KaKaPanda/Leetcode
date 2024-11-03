class Solution {
public:
    // 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
    // 输入：nums = [5,7,7,8,8,10], target = 8
    // 输出：[3,4]
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        if (nums.size() == 0) return res; 
        if (target < nums[0] || target > nums[nums.size()-1]) return res; // target不在范围内直接返回

        // 二分法搜索, 找到左边索引
        int left = 0, right = nums.size();
        if (nums[left] == target) {
            res[0] = left; // 先处理掉边界
        } else {
            while (left + 1 != right) { // 边界已提前处理，这个判断条件不会导致死循环
                int mid = (left + right) / 2;
                if (nums[mid] == target && nums[mid-1] != target) {
                    res[0] = mid;
                    break;
                }

                if (nums[mid] < target) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
        }

        if (res[0] == -1) return res;

        // 二分法搜索, 找到右边索引
        left = res[0]-1, right = nums.size()-1; // 这里范围要左移一下
        if (nums[right] == target) {
            res[1] = right; // 先处理掉边界
        } else {
            while (left + 1 != right) {
                int mid = (left + right) / 2;
                if (nums[mid] == target && nums[mid+1] != target) {
                    res[1] = mid;
                    break;
                }

                if (nums[mid] > target) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
        }
        return res;
    }
};