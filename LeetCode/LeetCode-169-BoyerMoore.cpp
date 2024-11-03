class Solution {
public:
    // 尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (auto & n : nums) {
            if (count == 0) {
                candidate = n;
                ++count;
                continue;
            } else if (n == candidate) {
                ++count;
            } else {
                --count;
            }
        }
        return candidate;
    }
};