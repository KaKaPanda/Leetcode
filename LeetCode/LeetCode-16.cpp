class Solution {
public:
    long abs(long num) {
        return num >= 0? num : -num;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-2; ++i) {
            int j = i + 1, k = nums.size() - 1;  // 双指针法
            while (j < k) {
                int temp = nums[i] + nums[j] + nums[k];
                if (temp == target) {
                    return target; // 提前退出
                } else if (temp < target) {
                    ++j;
                } else if (temp > target) {
                    --k;
                } else {
                    ; // 不可能进入
                }
                
                if (abs(long(temp) - target) <= abs(long(res) - target)) {
                    res = temp;
                }
            }
        }

        return res;
    }
};