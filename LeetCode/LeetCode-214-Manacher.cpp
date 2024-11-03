class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() <= 1) return s;

        vector<int> arm_vec(2 * s.size() + 1, 0);
        std::string str_vec(2 * s.size() + 1, '.');
        for (int i = 0; i < s.size(); ++i) {
            str_vec[2 * i + 1] = s[i];
        }
        
        int max_arm_mid = 0, max_arm_len = 0;  // 记录最长回文串位置
        int cur_arm_mid = 0, cur_arm_edg = -1; // 记录当前回文窗口

        for (int i = 0; i < arm_vec.size(); ++i) {
            int tmp_arm_len = 0;
            if (i > cur_arm_edg) { // 索引在臂长边界外，中心探索
                // tmp_arm_len = 0;
            } else if (i + arm_vec[2 * cur_arm_mid - i] <= cur_arm_edg) { // 索引在臂长边界内，加上对称位置臂长也在臂长边界内
                tmp_arm_len = arm_vec[2 * cur_arm_mid - i];
            } else { // 索引在臂长边界内，加上对称位置臂长在臂长边界外
                tmp_arm_len = cur_arm_edg - i;
            }

            while (i - tmp_arm_len - 1 >= 0 && i + tmp_arm_len + 1 < str_vec.size()) {
                if (str_vec[i - tmp_arm_len - 1] != str_vec[i + tmp_arm_len + 1]) break;
                ++tmp_arm_len;
            }

            arm_vec[i] = tmp_arm_len;

            if (tmp_arm_len > max_arm_len && i - tmp_arm_len == 0) { // 更新最大臂长和中心, 限定回文串从索引0开始
                max_arm_len = tmp_arm_len;
                max_arm_mid = i;
            }
            if (i + tmp_arm_len > cur_arm_edg) { // 更新臂长可达的最大索引和中心
                cur_arm_edg = i + tmp_arm_len;
                cur_arm_mid = i;
            }
        }


        string tmp(s.rbegin(), s.rbegin() + (s.size() - max_arm_len));
        return tmp + s;
    }
};