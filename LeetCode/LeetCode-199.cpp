class Solution {
public:
    // 每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。
    // 不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        std::unordered_map<char, char> st_map, ts_map;
        for (int i = 0; i < s.size(); ++i) {
            auto found1 = st_map.find(s[i]);
            auto found2 = ts_map.find(t[i]);

            if (found1 == st_map.end() && found2 == ts_map.end()) {
                st_map[s[i]] = t[i];
                ts_map[t[i]] = s[i];
            } else if (found1 != st_map.end() && found2 != ts_map.end()) {
                if (found1->second != t[i] || found2->second != s[i]) {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }
};