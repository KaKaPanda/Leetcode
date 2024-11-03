class Solution {
public: 
    // dp[i][j][k][h] 表示 T[k..h] 是否由 S[i..j] 变来。
    // 由于变换必须长度是一样的，因此这边有个关系 j−i=h−k ，可以把四维数组降成三维。
    // dp[i][j][len] 表示从字符串 S 中 i 开始长度为 len 的字符串是否能变换为从字符串 T 中 j 开始长度为 len 的字符串
    // 时间复杂度：O(n^4)，其中 n 是给定的原始字符串的长度。
    // 空间复杂度：O(n^3)，即为存储所有动态规划状态需要的空间。

    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false; // 字数不相等直接退出

        string ss1 = s1, ss2 = s2;
        std::sort(ss1.begin(), ss1.end());
        std::sort(ss2.begin(), ss2.end());
        if (ss1 != ss2) return false; // 简单判断是否可解

        vector<vector<vector<bool>>> dp = vector<vector<vector<bool>>>(s1.size(), 
                vector<vector<bool>>(s1.size(), vector<bool>(s1.size(), 0)));

        for (int k = 1; k <= s1.size(); ++k) { // 长度k要放在最外一层循环
            for (int i = 0; i + k - 1 < s1.size(); ++i) {
                for (int j = 0; j + k - 1 < s1.size(); ++j) {

                    if (k == 1) {
                        dp[i][j][0] = (s1[i] == s2[j]);
                    }
                    else {
                        for (int l = 1; l < k; ++l) { // k 为长度, 分解为 l, k-l
                            if ((dp[i][j][l-1] && dp[i+l][j+l][k-l-1]) == true) {
                                dp[i][j][k-1] = true;
                                break;
                            }
                            if (dp[i][j+k-l][l-1] && dp[i+l][j][k-l-1] == true) {
                                dp[i][j][k-1] = true;
                                break;
                            }
                        } 
                    }
                }
            }
        }

        return dp[0][0][s1.size()-1];
    }
};

// 递归方法搜索路径太多，无法复用子问题计算结果，渐进时间复杂度为N!, 因此随着长度增加必定会超时
/*
class Solution {
public: 
    bool isSubScramble(const string& s1, const string& s2) {
        if (s1.size() != s2.size()) return false; // 字数不相等直接退出
        else if (s1.size() <= 1) return s1 == s2; // 递归退出条件

        int mismatch_char_left = 0, mismatch_char_right = 0;
        std::unordered_map<char, int> match_map_left, match_map_right;

        // 正序和逆序同时匹配s2的前半段，找到分界点, 这里循环条件不能包含最后一个元素
        for (int i = 0, j = s1.size()-1; i < s1.size()-1 && j > 0; ++i, --j) {
            if (s1[i] != s2[i]) { // 正序查找
                mismatch_char_left += (match_map_left[s1[i]] < 0)? -1 : 1;
                match_map_left[s1[i]]++;
                mismatch_char_left += (match_map_left[s2[i]] > 0)? -1 : 1;
                match_map_left[s2[i]]--;
            }
            if (s1[j] != s2[i]) { // 逆序查找, 这里s2的索引还是i
                mismatch_char_right += (match_map_right[s1[j]] < 0)? -1 : 1;
                match_map_right[s1[j]]++;
                mismatch_char_right += (match_map_right[s2[i]] > 0)? -1 : 1;
                match_map_right[s2[i]]--;
            }

            if (mismatch_char_left == 0) { // 正序匹配
                if (isScramble(s1.substr(0, i+1), s2.substr(0, i+1)) && 
                    isScramble(s1.substr(i+1, s1.size()-i-1), s2.substr(i+1, s2.size()-i-1))) {
                    return true;
                } // false 继续查找
            }
            if (mismatch_char_right == 0) { // 逆序匹配
                if (isScramble(s1.substr(j, s1.size()-j), s2.substr(0, s2.size()-j)) &&
                    isScramble(s1.substr(0, j), s2.substr(s2.size()-j, j))) {
                    return true;
                } // false 继续查找
            }
        }

        return false; // 包含字母无法匹配以及完全错序情况
    }

    bool isScramble(string s1, string s2) {
        string ss1 = s1, ss2 = s2;
        std::sort(ss1.begin(), ss1.end());
        std::sort(ss2.begin(), ss2.end());
        if (ss1 != ss2) return false; // 最外层需要简单判断是否可解，否则会超时
        return isSubScramble(s1, s2);
    }
};
*/