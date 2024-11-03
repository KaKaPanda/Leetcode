class Solution {
public:
    // 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 子集（幂集）。
    // 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
    vector<vector<int>> subsetsWithDup(vector<int>& nums) { // 类似78题
        vector<int> uni_nums;
        std:unordered_map<int, int> num_count_map;

        std::sort(nums.rbegin(), nums.rend());

        for (int i = 0; i < nums.size(); ++i) {
            if (num_count_map.find(nums[i]) == num_count_map.end()) {
                uni_nums.push_back(nums[i]);
                num_count_map[nums[i]] = 1;
            } else {
                ++num_count_map[nums[i]];
            }
        }

        vector<vector<int>> res;
        int uni_count = uni_nums.size();
        for (int i = 0; i < pow(2, uni_count); ++i) { // 使用二进制左移来求解: 00110
            int index = 0, bits = i;
            vector<int> vec;

            while (bits > 0) {
                if (bits & 0x01) {
                    vec.push_back(uni_nums[index]);
                }
                bits >>= 1;
                ++index;
            }

            res.push_back(vec); // 压入唯一数字的子集, 其中包括空集

            int mark_size = res.size();
            for (int j = 0; j < vec.size(); ++j) {

                vector<vector<int>> add_res;
                int num_count1 = num_count_map[vec[j]], num_count2 = num_count1;

                if (mark_size < res.size()) { // 非第一个重复数字
                    while (num_count1-- > 1) {
                        for (int k = mark_size; k < res.size(); ++k) { // 需要前面有其他重复元素的遍历一遍
                            add_res.emplace_back(res[k]);
                            add_res.back().push_back(vec[j]);
                        }
                    }
                }

                vector<int> copy_vec = vec;
                while (num_count2-- > 1) { // 仅压入当前重复数字
                    copy_vec.push_back(vec[j]);
                    add_res.push_back(copy_vec);
                }

                std::copy(add_res.begin(), add_res.end(), back_inserter(res));
            }
        }
        return res;
    }
};