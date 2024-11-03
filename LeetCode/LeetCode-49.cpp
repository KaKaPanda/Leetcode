class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> str_index_map;

        int index = 0;
        for (int i = 0; i < strs.size(); ++i) {
            string str = strs[i];
            std::sort(str.begin(), str.end());
            auto found = str_index_map.find(str);
            if (found == str_index_map.end()) {
                str_index_map[str] = index++;
                res.push_back(vector<string>{strs[i]});
            } else {
                int found_index = found->second;
                res[found_index].push_back(strs[i]);
            }
        }
        return res;
    }
};