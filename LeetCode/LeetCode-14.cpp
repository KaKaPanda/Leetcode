class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common_prefix = "";
        if (strs.size() == 0) return common_prefix;

        while (true) {
            int index = common_prefix.size();
            if (strs[0].size() <= index) { // 判断第一个字符串长度
                return common_prefix;
            } 
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i].size() <= index) { // 判读后续字符串长度
                    return common_prefix;
                } else if (strs[i][index] != strs[0][index]) { // 字符不一致直接返回
                    return common_prefix;
                }
            }
            common_prefix += strs[0][index]; // 加入新字符
        }

        return common_prefix;
    }
};