class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorSum = 0;
        for (auto & num : nums) xorSum ^= num;
        if (xorSum == 0) return {};

        // 将数分为两类分别进行 xor
        int mask = 0x01;
        while ((mask & xorSum) == 0) mask <<= 1; // 注意这里的运算优先级

        int num1 = 0, num2 = 0;
        for (auto & num : nums) {
            if (num & mask) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        return {num1, num2};
    }
};