class Solution {
public:
    string reverseWords(string s) {
        std::reverse(s.begin(), s.end());

        int p = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (p == 0 && s[i] == ' ') continue; // 跳过前导空格
            if (i > 0 && s[i] == ' ' && s[i-1] == ' ') continue; // 跳过连续空格
            s[p++] = s[i];
        }
        if (s[p-1] == ' ') --p; // 去除结束空格
        s = s.substr(0, p);

        int beg_pos = 0;
        while (true) {
            auto found_pos = s.find(' ', beg_pos);
            if (found_pos == std::string::npos) {
                std::reverse(s.begin()+beg_pos, s.end());
                break;
            }
            std::reverse(s.begin()+beg_pos, s.begin()+found_pos);
            beg_pos = found_pos + 1;
        }

        return s;
    }
};