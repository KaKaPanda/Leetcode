class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() == 0 || s.size() < t.size()) return ""; // 长度无法匹配

        std::unordered_map<char, int> alpha_count_map;
        for (auto &c : t) {
            ++alpha_count_map[c];
        }

        string min_match_string;
        std::queue<pair<char, int>> alpha_index_queue;
        std::unordered_map<char, int> match_count_map;
        int match_count_valid = 0;

        for (int i = 0; i < s.size(); ++i) {
            auto found = alpha_count_map.find(s[i]);
            if (found == alpha_count_map.end()) {
                continue;
            }

            alpha_index_queue.push(pair<char, int>(s[i], i));
            ++match_count_map[s[i]];
            if (match_count_map[s[i]] <= found->second) { // 元素还有缺失
                ++match_count_valid;
            } else { // 元素个数超出
                auto alpha_index = alpha_index_queue.front(); // 且与队头元素相等，循环弹出超额元素
                while (match_count_map[alpha_index.first] > alpha_count_map[alpha_index.first]) {
                    alpha_index_queue.pop();
                    --match_count_map[alpha_index.first];
                    if (!alpha_index_queue.empty()) {
                        alpha_index = alpha_index_queue.front();
                    } else {
                        break;
                    }
                }
            }

            if (match_count_valid == t.size()) {
                auto head_alpha_index = alpha_index_queue.front();
                auto tail_alpha_index = alpha_index_queue.back();
                int len = tail_alpha_index.second - head_alpha_index.second + 1;
                if (min_match_string.empty()) {
                    min_match_string = s.substr(head_alpha_index.second, len);
                } else if (len < min_match_string.size()) {
                    min_match_string = s.substr(head_alpha_index.second, len);
                }
            } 
        }
        return min_match_string;
    }
};