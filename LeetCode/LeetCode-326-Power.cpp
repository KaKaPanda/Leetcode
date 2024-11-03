class Solution {
public:
    // 进阶：你能够不使用循环/递归解决此问题吗？
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;       // 注意处理负数
        return 1162261467 % n == 0;     // 判断是否为最大 3 的幂的约数
    }
};