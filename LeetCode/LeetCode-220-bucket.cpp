class Solution {
private:
    int get_bucket_id(const int n, const int bucket_size) { // 将整数每隔 valueDiff 分为一个桶
        return (n < 0) ? (n + 1) / bucket_size - 1 : n / bucket_size; // 注意处理负区间
    }

public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        std::unordered_map<int, int> buckets;

        for (int i = 0; i < nums.size(); ++i) {
            int buck_ind = get_bucket_id(nums[i], valueDiff+1);
            if (buckets.find(buck_ind) != buckets.end()) {
                return true; // 同一个桶出现重复
            }
            buckets[buck_ind] = nums[i]; // 桶插入元素
            
            auto prev_buck = buckets.find(buck_ind - 1);
            auto next_buck = buckets.find(buck_ind + 1);
            if (prev_buck != buckets.end() && abs(prev_buck->second - nums[i]) <= valueDiff) {
                return true; // 与上一个桶比较
            }
            if (next_buck != buckets.end() && abs(next_buck->second - nums[i]) <= valueDiff) {
                return true; // 与下一个桶比较
            }

            if (buckets.size() > indexDiff) {
                buckets.erase(get_bucket_id(nums[i - indexDiff], valueDiff+1)); // 移动窗口，桶删除元素
            }
        }
        return false;
    }
};