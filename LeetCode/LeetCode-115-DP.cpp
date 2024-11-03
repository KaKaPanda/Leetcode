class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size() || t.size() == 0) return 0;

        int res = 0;
        vector<vector<int>> dp = vector<vector<int>>(s.size()+1, vector<int>(t.size()+1, 0));
        for (int i = 0; i <= s.size(); ++i) { // 右方和下方进行padding，避免索引越界
            dp[i][t.size()] = 1;
        }

        for (int j = t.size()-1; j >= 0; --j) {
            int cur_match_count = 0; // 当前索引起始字符串匹配计数
            int pre_match_count = 0; // 后续索引起始字符串匹配计数
            for (int i = s.size()-1; i >= 0; --i) {
                pre_match_count = max(pre_match_count, dp[i+1][j+1]); // 这里要拿右下方的值
                if (t[j] == s[i]) {
                    cur_match_count += pre_match_count;
                    if (cur_match_count >= long(1E9)+7) {
                        cur_match_count %= long(1E9)+7;
                    }
                }
                dp[i][j] = cur_match_count;
            }
        }

        return dp[0][0];
    }
};