class Solution {
private:
    int findPeakElement(const vector<int>& nums, int left, int right) {
    while (left + 1 < right) { // 保证前后有三个元素
        int mid = (left + right) / 2;
        if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
            return mid;
        }

        if (nums[mid] < nums[mid + 1]) { // 右边比较高，往高处走
            left = mid;
        } else if (nums[mid] < nums[mid - 1]) {
            right = mid;
        } else {
            return -1;
        }
    }

    if (nums[left] > nums[left+1] && nums[left] > nums[left-1]) return left;
    if (nums[right] > nums[right+1] && nums[right] > nums[right-1]) return right;  
    return -1;
}

public:
    int findPeakElement(vector<int>& nums) { // 题目中: 对于所有有效的 i 都有 nums[i] != nums[i + 1]
        int sz = nums.size();
        if (sz <= 1) return sz - 1;

        // 先排除掉边界情况
        int left = 0, right = sz - 1;
        if (nums[left] > nums[left+1]) return left;
        if (nums[right] > nums[right-1]) return right;

        return findPeakElement(nums, left, right);
    }
};