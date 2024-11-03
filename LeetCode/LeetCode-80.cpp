class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, prev = 0, recur = 0;
        if (nums.size() > 0) {
            count = 1;
            recur = 1;
            prev = nums[0];
        }

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == prev) {
                ++recur;
            } else {
                prev = nums[i];
                recur = 1;  // 计数重置
            }

            if (recur <= 2) {
                if (i != count) {
                    nums[count] = nums[i];
                }
                ++count;
            } else {
                ; // do nothing
            }
        }

        return count;
    }
};