class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int xx = x, base = 1;  // 缩减查找范围，但无法解决大数相乘问题
        while (xx) {
            xx /= 100;
            base *= 10;
        }

        int left = base/10, right = base;
        while (left + 1 != right) {
            int mid = (left + right) / 2;
            double mul = double(mid) * double(mid), mul1 = double(mid+1) * double(mid+1);
            if (mul <= x && mul1 > x) {
                return mid;
            }

            if (mul < x) {
                left = mid;
            } else if (mul > x) {
                right = mid;
            }
        }
        return left;
    }
};