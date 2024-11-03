class Solution {
public:
    int longestValidParentheses(string s) { // (()(((() ; ))))())()()(()
        int left = 0, right = 0, max_len = 0; 

        for (int i = 0; i < s.size(); ++i) { // 先从左往右扫描
            if (s[i] == '(') {
                ++left;
            } else if (s[i] == ')') {
                ++right;
            }
            if (left == right) {  // 数量相等更新最大值
                max_len = max(max_len, left*2);
            } else if (right > left) { // 数量超出重置
                left = right = 0;
            }
        }

        left = right = 0;
        for (int i = s.size()-1; i >= 0; --i) { // 再从右往左扫描
            if (s[i] == ')') {
                ++right;
            } else if (s[i] == '(') {
                ++left;
            }
            if (left == right) {
                max_len = max(max_len, left*2);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return max_len;
    }
};