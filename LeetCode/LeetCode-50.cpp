class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;

        double res = 1;
        bool negative = (n < 0);
        long pow = (n > 0)? long(n) : -long(n); // 使用long来避免数值溢出
        while (pow != 0) {
            long acc_pow = 1;
            double acc_x = x;
            while (acc_pow*2 < pow) { // 二分法逼近
                acc_pow *= 2;
                acc_x *= acc_x;
            }
            pow -= acc_pow;
            res *= acc_x;
        }
        return (negative)? 1/res : res; // 负数返回倒数
    }
};