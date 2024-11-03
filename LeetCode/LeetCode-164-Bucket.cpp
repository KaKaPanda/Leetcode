class Solution {
public:
    // 给定一个无序的数组 nums，返回 数组在排序之后，相邻元素之间最大的差值。如果数组元素个数小于 2，则返回 0 。
    // 您必须编写一个在「线性时间」内运行并使用「线性额外空间」的算法。
    // 1. 基数排序可以在 O(N) 的时间内完成整数之间的排序。(但是负数有点麻烦)
    int maximumGap(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 1) return 0;

        int maxV = nums[0];
        for (auto & n : nums) maxV = max(maxV, n);

        int base = 1;
        while (base <= maxV) { // 注意等于号
            vector<vector<int>> buckets = vector<vector<int>>(10, vector<int>{});

            for (auto & n : nums) {
                int idx = (n / base) % 10;
                buckets[idx].push_back(n);
            }
            base *= 10;

            nums.clear();
            for (auto & bucket : buckets) {
                std::move(bucket.begin(), bucket.end(), back_inserter(nums));
            }
        }

        int ans = 0;
        for (int i = 1; i < nums.size(); ++i) {
            ans = max(ans, nums[i] - nums[i-1]);
        }
        return ans;
    }

    // 2. 基于桶间隔的算法, 间隔最大的不可能存在桶内, 而是在桶之间
    int maximumGap2(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 1) return 0;

        int maxV = *max_element(nums.begin(), nums.end());
        int minV = *min_element(nums.begin(), nums.end());

        int distance = max(1, (maxV - minV) / (sz - 1));  // 限制桶个数最小为1
        int buck_num = (maxV - minV) / distance + 1;      // 这里不能直接写 nums.size()
        vector<pair<int, int>> buckets(buck_num, pair<int, int>{INT_MIN, INT_MAX});

        for (auto & n : nums) {
            int buck_idx = (n - minV) / distance;
            buckets[buck_idx].first = max(buckets[buck_idx].first, n);   // 存储桶的最大值
            buckets[buck_idx].second = min(buckets[buck_idx].second, n); // 存储桶的最小值
        }

        int ans = 0;
        pair<int, int> last_buck{INT_MIN, INT_MAX};
        for (int i = 0; i < buckets.size(); ++i) {
            if (buckets[i].first == INT_MIN && buckets[i].second == INT_MAX) {
                continue; // 跳过空桶
            }
            if (last_buck.first != INT_MIN || last_buck.second != INT_MAX) {
                ans = max(ans, buckets[i].second - last_buck.first);
            }
            last_buck = buckets[i];
        }
        return ans;
    }
};