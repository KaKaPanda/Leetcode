class Solution {
public:
    int romanToInt(string s) {
        int res = 0;  //0123456
        string roman = "IVXLCDM";

        for (int i = 0, step = 1; i < s.size(); i += step) {
            auto index = roman.find(s[i]);
            int powTen = index / 2;
            int isFive = index % 2;
            
            step = 1; // 这个step每次循环要重置

            if (!isFive && i+step < s.size() && s[i+step] == s[i]) {
                // 不是5且后面有字符进行步进计数
                ++step;
            }

            bool isNegative = false;
            if (!isFive && i+step < s.size() && roman.find(s[i+step]) > index) {
                // 小罗马后面是大罗马，需要做减法
                isNegative = true;
            }
            
            int number = step * pow(10, powTen) * (isFive? 5 : 1);
            
            if (isNegative) {
                res -= number;
            } else {
                res += number;
            }
        }
        return res;
    }
};