class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end()); // 先对原数组进行排序

        std::unordered_map<long, int> num_count_map; // map: 数值->频次
        for (int i = 0; i < nums.size(); ++i) {
            auto found = num_count_map.find(nums[i]);
            if (found == num_count_map.end()) {
                num_count_map[nums[i]] = 1;
            } else {
                num_count_map[nums[i]] += 1;
            }
        }

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue; // 跳过相同的第一个元素
            }
            for (int j = i+1; j < nums.size(); ++j) { // 限制 i < j
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue; // 跳过相同的第二个元素
                }
                for (int k = j+1; k < nums.size(); ++k) { // 限制 j < k
                    if (k > j+1 && nums[k] == nums[k-1]) {
                        continue; // 跳过相同的第三个元素
                    }
                    long temp = target - (long(nums[i]) + nums[j] + nums[k]);
                    if(temp < nums[k]) {
                        continue; // 限制 k < l
                    }
                    int count = (nums[i]==temp) + (nums[j]==temp) + (nums[k]==temp);
                    auto found = num_count_map.find(temp);
                    if (found == num_count_map.end()) {
                        continue; // 找不到数直接跳过
                    } else if (found->second > count) {
                        result.push_back({nums[i], nums[j], nums[k], int(temp)});
                    }
                }
            }
        }

        return result;
    }
};