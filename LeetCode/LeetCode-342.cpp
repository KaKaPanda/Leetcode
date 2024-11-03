class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false; // 注意处理负数
        return (n & (n-1)) == 0 && (n & 0xaaaaaaaa) == 0; // 位运算技巧
        return (n & (n-1)) == 0 && n % 3 == 1;            // 如果 n 是 4 的幂，那么它除以 3 的余数一定为 1
    }
};