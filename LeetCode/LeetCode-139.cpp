class Solution {
public:
    // 10101010
    // "aaaaaaa" ["aaaa","aa"] 这里转换为邻接表求解会有错漏
    bool wordBreak(string s, vector<string>& wordDict) {
        int sz = s.size();
        if (sz == 0) return true;
        if (wordDict.size() == 0) return false;        

        std::unordered_set<string> wordMap;
        for (auto & word : wordDict) {
            wordMap.insert(word);
        }

        vector<bool> reachable = vector<bool>(sz+1, false);
        reachable[0] = true;

        for (int i = 1; i <= sz; ++i) {
            for (int j = i; j <= sz; ++j) {
                if (wordMap.find(s.substr(i-1, j-i+1)) != wordMap.end() && reachable[i-1] == true) {
                    reachable[j] = true; // 这里只标记结尾索引，起始索引不需要标记
                }
            }
        }

        return reachable[sz];
    }
};