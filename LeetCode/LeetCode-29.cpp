class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if (divisor == 0) return 0; // error
        else if (divisor == 1) return dividend;
        else if (divisor == -1) {
            return (dividend == INT_MIN)? INT_MAX : -dividend;
        } else if (divisor == INT_MIN) { // // 除数 =INT_MIN 特殊处理
            return (dividend == INT_MIN)? 1 : 0;
        }

        bool min_flag = false;
        bool negative = false;
        if (dividend < 0) { // 转为正数进行计算
            min_flag = (dividend == INT_MIN);
            dividend = (dividend == INT_MIN)? INT_MAX : -dividend;
            negative = !negative;
        }

        if (divisor < 0) { // 除数 =INT_MIN 前面已处理
            divisor = -divisor;
            negative = !negative;
        }

        int res = 0;  // 需要初始化零
        while (dividend - divisor >= 0) { // 注意判断条件
            int cnt_divisor = 1;
            int acc_divisor = divisor;
            
            // acc_divisor + acc_divisor < dividend 会超出数值范围
            while (acc_divisor < dividend - acc_divisor) { // 需要使用二分法，否则会超时
                cnt_divisor += cnt_divisor;
                acc_divisor += acc_divisor;
            }

            dividend -= acc_divisor;
            res += cnt_divisor;
            
            if (min_flag == true) {
                min_flag = false;
                dividend += 1;
            }
        }
        return (negative)? -res: res;
    }
};