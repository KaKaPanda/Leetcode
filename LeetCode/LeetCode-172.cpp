class Solution {
public:
    // 设计并实现对数时间复杂度的算法来解决此问题
    // n! 尾零的数量即为 n! 中因子 10 的个数，而 10=2×5，
    // 因此转换成求 n! 中质因子 2 的个数和质因子 5 的个数的较小值。
    // 由于质因子 5 的个数不会大于质因子 2 的个数，我们可以仅考虑质因子 5 的个数。

    int trailingZeroes(int n) {
        int ans = 0;

        while (n > 0) {
            n /= 5;
            ans += n;
        }

        return ans;
    }
};