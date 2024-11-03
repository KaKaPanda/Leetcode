class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>());
        int count = nums.size();

        for (int i = 1; i < pow(2, count); ++i) {  // 使用二进制左移来求解
            int index = 0, bits = i;
            vector<int> vec;
            while (bits > 0) {
                if (bits & 0x01) {
                    vec.push_back(nums[index]);
                }
                ++index;
                bits >>= 1;
            }
            res.push_back(vec);
        }
        return res;
    }
};