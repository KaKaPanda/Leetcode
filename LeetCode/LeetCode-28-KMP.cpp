class Solution {
public:
    int strStr(string haystack, string pattern) { // KMP 加快匹配
        // 长度为0直接返回
        int n = haystack.size(), m = pattern.size();
        if (m == 0) {
            return 0;
        }

        // 生成 next 数组
        haystack = " " + haystack; // 在前面加空格
        pattern = " " + pattern;
        vector<int> next(m+1, 0);

        int cur = 0;
        for (int i = 2; i < next.size(); ++i) {
            while (cur > 0 && pattern[i] != pattern[cur+1]) {
                cur = next[cur]; // 下一个字符无法匹配, 跳转到上一个索引
            }
            if (pattern[i] == pattern[cur+1]) {
                ++cur;
            }
            next[i] = cur;
        }

        // 使用 next 数组辅助进行匹配
        cur = 0;
        for (int i = 1; i < haystack.size(); ++i) {
            while (cur > 0 && haystack[i] != pattern[cur+1]) {
                cur = next[cur];
            }
            if (haystack[i] == pattern[cur+1]) {
                ++cur;
            }
            if (cur == m) { // 完全匹配
                return i - m;
            }
        }
        return -1; // 无法匹配

    }
};