class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 0) return "";

        stringstream ss;
        vector<long long> vec(n+1, 1);
        for (int i = 1; i <= n; ++i) {
            ss << i;
            vec[i] = vec[i-1] * i;  // X 1 2 6 24 ...
        }
        if (k > vec.back()) return ""; // 超出范围直接返回

        string raw = ss.str(), res;
        for (int i = n; i >= 1; --i) { // 循环生成第 i 个字符
            if (k == 1) {
                return res + raw; // 直接拼接剩余字符
            }

            int base = vec[i-1];
            int multi = (k-1) / base; // k-1处理进位边界
            k -= base * multi;
            res += raw[multi];
            raw.erase(raw.begin()+multi);
        }
        return res;
    }
};