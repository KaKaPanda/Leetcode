class Solution {
public:
    // 进阶：你能够不使用循环/递归解决此问题吗？
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false; // 注意处理负数
        return (n & (n-1)) == 0;  // 位运算技巧1
        return (n & -n) == n;     // 位运算技巧2
    }
};