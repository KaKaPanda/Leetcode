class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); // 先对原数组进行排序

        unordered_map<int, int> num_count_map; // map: 数值->频次
        for (int i = 0; i < nums.size(); ++i) {
            auto found = num_count_map.find(nums[i]);
            if (found == num_count_map.end()) {
                num_count_map[nums[i]] = 1;
            } else {
                num_count_map[nums[i]] += 1;
            }
        }

        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue; // 跳过相同的第一个元素
            }
            for (int j = i+1; j < nums.size(); ++j) { // 限制 i < j
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue; // 跳过相同的第二个元素
                }

                int temp = -(nums[i] + nums[j]);
                if (temp < nums[j]) {
                    continue; // 限制 j < k
                }

                auto found_k = num_count_map.find(temp);
                if (found_k == num_count_map.end()) { // 找不到数直接跳过
                    continue;
                } else if (temp != nums[i] && temp != nums[j]) {
                    res.push_back(vector<int>{nums[i], nums[j], temp});
                } else if ((temp != nums[i] || temp != nums[j]) && found_k->second >= 2) { // 注意运算符优先级
                    res.push_back(vector<int>{nums[i], nums[j], temp});
                } else if ((temp == nums[i] && temp == nums[j]) && found_k->second > 2) {
                    res.push_back(vector<int>{nums[i], nums[j], temp});
                }
            }
        }
        return res;
    }
};