class Solution {
public:
    vector<vector<int>> subPermuteUnique(vector<int>& nums, int bits) {  // 使用bits来表示占用
        vector<vector<int>> res;
        if (nums.size() == 0 || bits == 0) return res;

        int mask = 1, index = 0; // 利用mask左移进行位运算选取元素
        unordered_set<int> nums_set;
        while (index < nums.size()) {
            if (bits & mask) { // 当前循环使用bits与mask的位与运算来选取元素
                int number = nums[index];

                if (nums_set.find(number) != nums_set.end()) { // 利用set筛除当前循环重复出现的元素
                    ++index;
                    mask <<= 1;
                    continue;
                } else {
                    nums_set.insert(number);
                }

                int new_bits = bits & ~mask;
                if (new_bits == 0) {  // 提前退出条件
                    res.push_back(vector<int>{number});
                    return res;
                }
                vector<vector<int>> sub_res = subPermuteUnique(nums, new_bits);
                for (int i = 0; i < sub_res.size(); ++i) {
                    sub_res[i].push_back(number);
                    res.push_back(sub_res[i]);
                }
            }
            ++index;
            mask <<= 1; 
        }
        return res;
    }

    // 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int bits = pow(2, nums.size()) - 1;

        return subPermuteUnique(nums, bits);
    }
};