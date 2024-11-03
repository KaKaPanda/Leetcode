class Solution {
public:
    vector<int> res;

    vector<int> matchSubstring(const string& s, int st, int wl, int wc, int mc,
            const std::unordered_map<string, int>& word_count_map) {
        std::unordered_map<string, int> seen_count_map;  // 使用 seen_count_map 和 word_count_map 对比效率更高
        for (int i = st; i < s.size() && i+wl <= s.size(); i += wl) {
            if (mc == wc) {
                string head_word = s.substr(st, wl);
                --seen_count_map[head_word];
                st += wl; // 步进窗口起点
                --mc; // 递减匹配计数
            }

            string word = s.substr(i, wl);
            auto found = word_count_map.find(word);
            if (found == word_count_map.end()) {
                seen_count_map.clear();
                st = i + wl; // 步进窗口起点
                mc = 0;  // 匹配不上重置计数
                continue;
            } else if (seen_count_map[word] == found->second) {
                while (true) {
                    string head_word = s.substr(st, wl);
                    st += wl;
                    if (head_word == word) break; // 循环步进窗口直到遇到相同单词
                    --seen_count_map[head_word];
                    --mc;
                }
            } else {
                ++seen_count_map[word];
                if (++mc == wc) res.push_back(st); // 压入索引
            }
        }

        return res;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.size() == 0 || words.size() == 0 || words[0].size() == 0) return res;

        std::unordered_map<string, int> word_count_map;
        for (auto &word : words) {
            word_count_map[word]++;
        }
        
        int word_length = words[0].size();
        int words_count = words.size();
        int match_count = 0;

        for (int i = 0; i < s.size() && i < word_length; ++i) { // 这里只需要循环 word_length 次
            if (i+word_length*(words_count) > s.size()) break;
            matchSubstring(s, i, word_length, words_count, match_count, word_count_map);
        }
        return res;
    }
};
