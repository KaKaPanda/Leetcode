class Solution {
public:
    int longestConsecutive(vector<int>& nums) { // 需要使用unordered_set或者map，时间复杂度才为O(n)
        if (nums.empty()) return 0;
        
        std::unordered_map<int, int> nums_map;
        for (auto &n : nums) {
            nums_map[n] = 1;
        }

        int longest = 1;
        for (auto iter = nums_map.begin(); iter != nums_map.end(); ++iter) { 
            int num = iter->first;
            if (num == INT_MIN || iter->second > 1) continue; // 遇到 INT_MIN 或者检索过的索引直接跳过

            int lower_num = num, lower_len = 0;
            while (num != INT_MIN && nums_map.find(num-1) != nums_map.end()) { // 直到遇到 INT_MIN 或者检索失败
                lower_len = nums_map[num-1];
                lower_num = --num;
                if (lower_len > 1) break;
            }

            for (int i = lower_num+1; i <= iter->first; ++i) { // 更新检索范围的连续长度
                nums_map[i] += lower_len;
                lower_len++;
            }
            
            longest = max(longest, iter->second);
        }
        return longest;
    }
};