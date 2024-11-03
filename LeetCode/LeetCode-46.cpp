class Solution {
public:
    vector<vector<int>> subPermute(vector<int>& nums, int bits) {  // 使用bits来表示占用
        vector<vector<int>> res;
        if (nums.size() == 0 || bits == 0) return res;

        int mask = 1, index = 0;
        while (index < nums.size()) {
            if (bits & mask) { // 当前循环使用bits与mask的位与运算来选取元素
                int number = nums[index];
                int new_bits = bits & ~mask;
                if (new_bits == 0) {  // 提前退出条件
                    res.push_back(vector<int>{number});
                    return res;
                }
                vector<vector<int>> sub_res = subPermute(nums, new_bits);
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

    // 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int bits = pow(2, nums.size()) - 1;

        return subPermute(nums, bits);
    }
};