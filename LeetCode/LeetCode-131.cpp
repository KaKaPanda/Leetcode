class Solution {
private:
    vector<vector<int>> cache_matrix;

    // 记忆化搜索，cache_matrix[i][j] = 0 表示未搜索，1 表示是回文串，-1 表示不是回文串
    bool check_palindrome(const string& s, const int& begin, const int& end) {
        // if (begin < 0 || end < 0 || begin > s.size() || end > s.size() || begin > end) return false;
        if (cache_matrix[begin][end] != 0) return cache_matrix[begin][end] == 1;
        for (int i = begin, j = end; i <= j; ++i, --j) {
            if (s[i] != s[j]) {
                cache_matrix[begin][end] = -1;
                return false;
            }
        }
        cache_matrix[begin][end] = 1;
        return true;
    }

    void reconstruct(vector<vector<string>>& res, const string& s, const int& ending) {
        vector<vector<string>> nex_res; 
        for (int begin = ending-1; begin >= 0; --begin) {
            if (check_palindrome(s, begin, ending) == true) { // 逐个跟先前字母匹配，成功则进行组装
                std::string str = s.substr(begin, ending-begin+1);
                if (begin == 0) {
                    nex_res.emplace_back(vector<string>{str}); // 整个前缀是个回文字符串
                    break;
                }

                std::unordered_set<long> sep_map; // 用于去重
                for (int i = 0; i < res.size(); ++i) { // 拿之前的计算结果，匹配wc相等的前缀序列
                    long long cnt = 0, sep_mask = 0;   // 由于题目字符长度 <=16, 这里拿long long来计算
                    vector<string>::iterator iter = res[i].begin();
                    while (iter != res[i].end() && cnt < begin) {
                        cnt += (*iter).size();
                        sep_mask |= 1 << cnt; // 将分隔位标记在 sep_mask
                        ++iter;
                    }
                    if (cnt == begin) {
                        if (sep_map.find(sep_mask) != sep_map.end()) { // 需要去除相同前缀
                            continue;
                        } else {
                            sep_map.insert(sep_mask);
                        }
                        nex_res.emplace_back(vector<string>(res[i].begin(), iter));
                        nex_res.back().emplace_back(str);
                    }
                }
            }
        }

        if (!nex_res.empty()) {
            std::move(nex_res.begin(), nex_res.end(), std::back_inserter(res)); // move 优化性能
        }
    };

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        res.emplace_back(vector<string>{});
        
        cache_matrix.assign(s.size(), vector<int>(s.size()));

        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < res.size(); ++j) {
                res[j].emplace_back(string()+s[i]); // 单个字符划分
            }
            reconstruct(res, s, i); // 单词与前面字符串搭配
        }
        return res;
    }
};