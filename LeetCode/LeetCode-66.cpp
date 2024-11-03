class Solution {
public:
    vector<int> plusOne(vector<int>& digits) { // 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字
        vector<int> res;
        bool flag = true;

        for (int i = digits.size()-1; i >= 0; --i) {
            int digit = digits[i] + flag;
            if (digit >= 10) {
                digit -= 10;
                flag = true;
            } else {
                flag = false; // 需要清除进位
            }
            res.push_back(digit);
        }

        if (flag) {
            res.push_back(1);
        }
        return vector<int>(res.rbegin(), res.rend());
    }
};