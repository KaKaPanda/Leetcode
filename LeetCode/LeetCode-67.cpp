class Solution {
public:
    string addBinary(string a, string b) { // 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和
        string res;
        bool flag = false;

        for (int i = a.size()-1, j = b.size()-1; i >=0 || j >= 0; --i, --j) {
            int ans = flag;
            if (i >= 0) ans += (a[i] - '0');
            if (j >= 0) ans += (b[j] - '0');
            
            if (ans >= 2) {  // 可能会超过2
                res += '0' + ans - 2;
                flag = true;
            } else {
                res += '0' + ans;
                flag = false; // 注意清除进位
            }
        }

        if (flag) res += '1';
        return string(res.rbegin(), res.rend());
    }
};