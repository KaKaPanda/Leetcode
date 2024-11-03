class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sz = nums.size();
        int minArrayLen = sz + 1; // 注意初始值
        int sumArrayVal = 0, start = 0, end = 0;

        while (sumArrayVal < target && end < sz) {
            while (sumArrayVal < target && end < sz) { // 循环增加数据
                if (nums[end] >= target) return 1;     // 单个数据满足直接返回
                sumArrayVal += nums[end++];
            }

            if (sumArrayVal >= target) {
                minArrayLen = min(minArrayLen, end - start);
            } else {
                break; // 说明数据用完了
            }

            while (sumArrayVal >= target && start < end) { // 循环缩减数据
                sumArrayVal -= nums[start++];
                if (sumArrayVal >= target) {               // 在缩减过程中也要注意更新范围
                    minArrayLen = min(minArrayLen, end - start);
                }
            }
        }
        return minArrayLen == (sz + 1) ? 0 : minArrayLen; 
    }
};