class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) { // 第一个元素直接 ++count
                count++;
                continue;
            }

            if (nums[i] == nums[count-1]) {
                continue;
            } else {
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};