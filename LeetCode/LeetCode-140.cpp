class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int sz = s.size();
        if (sz == 0 || wordDict.size() == 0) return vector<string>{};

        std::unordered_set<string> wordMap;
        for (auto & word : wordDict) {
            wordMap.insert(word);
        }

        std::vector<bool> reachable = std::vector<bool>(sz+1, false);
        reachable[0] = true;
        std::unordered_map<int, vector<string>> end_index_res;

        for (int i = 1; i <= sz; ++i) {
            for (int j = i; j <= sz; ++j) {
                std::string cut_word = s.substr(i-1, j-i+1);
                if (wordMap.find(cut_word) != wordMap.end() && reachable[i-1] == true) {
                    reachable[j] = true; // 这里只标记结尾索引，起始索引不需要标记
                    vector<string> vec = end_index_res[i-1]; // 拿到以上一个索引为结尾的计算结果
                    if (vec.empty()) {
                        vec.push_back(cut_word);
                    } else {
                        for (auto & sentence : vec) {
                            sentence += " " + cut_word;
                        }
                    }

                    if (end_index_res.find(j) == end_index_res.end()) {
                        end_index_res[j] = vec;
                    } else {
                        std::move(vec.begin(), vec.end(), back_inserter(end_index_res[j]));
                    }
                }
            }
        }
        return end_index_res[sz];
    }
};