class Solution {
public:
    int lengthOfLastWord(string s) {
        bool found_char = false;
        int word_right = s.size(), word_left = -1; // 注意兼容边界条件

        for (int i = s.size() - 1; i >= 0; --i) {
            if (!found_char && s[i] == ' ') {  // 忽略起始空格
                --word_right;
                continue;
            } else if (found_char && s[i] == ' ') { // 找到单词左边界
                word_left = i;
                break;
            } else {
                if (!found_char) {
                    found_char = true; // 找到单词右边界，设置标志位
                    word_right = i+1;
                }
            }
        }
        return word_right - word_left - 1;
    }
};