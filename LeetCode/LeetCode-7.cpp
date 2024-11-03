class Solution {
public:
    int reverse(int x) {
        bool minis = false; // 先转正数再反转
        if (x < 0) {
            if (x == INT_MIN) { // INT_MIN 单独处理返回
                return 0;
            }
            x = -x;
            minis = true;
        }

        int result = 0;
        while(x != 0) {
            int temp = x % 10;
            x = x / 10;
            // if (!minis) { // INT_MAX 处理正数
            //     if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && temp > INT_MAX % 10)) {
            //         return 0;
            //     }
            // } else { // 处理负数
            //     if (result > INT_MAX / 10) || (result == INT_MAX / 10 && temp > INT_MAX % 10 + 1) {
            //         return 0;
            //     }
            // }
            // 上述代码, 正数负数合并处理
            if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && temp > INT_MAX % 10 + minis)) {
                return 0; // 乘法操作前先判断会不会溢出
            } 
            result = result*10 + temp;
        }

        return minis?-result:result;
    }
};