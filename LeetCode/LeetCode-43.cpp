class Solution {
public:
    string add(string num1, string num2) { // 加法单独抽离
        if (num1.empty()) return num2;
        if (num2.empty()) return num1; 

        int p1 = num1.size() - 1, p2 = num2.size() - 1, flag = 0;

        string res;
        while (p1 >= 0 || p2 >= 0) {
            char sum = '0' + flag;
            if (p1 >= 0) sum += (num1[p1] - '0');
            if (p2 >= 0) sum += (num2[p2] - '0');
            if (sum > '9') {
                flag = 1; // 设置进位
                sum -= 10;
            } else {
                flag = 0; // 清除进位
            }
            res = sum + res;

            if (p1 >= 0) --p1;
            if (p2 >= 0) --p2;
        }
        if (flag == 1) res = '1' + res; // 处理最后的进位
        return res;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        string res;
        for (int i = num1.size()-1; i >= 0; --i) {
            string res_multi(num1.size() - 1 - i, '0'); // 乘法预先补零
            int cur = num1[i] - '0', flag = 0;
            for (int j = num2.size()-1; j >= 0; --j) {
                char mul = (num2[j] - '0') * cur + flag;
                flag = mul / 10;
                mul = mul % 10 + '0';
                res_multi = mul + res_multi;
            }
            if (flag >= 1) {
                char padding = flag + '0';
                res_multi = padding + res_multi;
            }
            res = add(res, res_multi);
        }
        return res;
    }
};