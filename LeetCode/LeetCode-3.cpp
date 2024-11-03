class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int fromIndex = 0;
        std::unordered_map<char, int> alphaMap; // k:字符-v:索引

        for (int currIndex = 0; currIndex < s.size(); ++currIndex) {
            auto preAlpha = alphaMap.find(s[currIndex]);
            if ( preAlpha == alphaMap.end()) { // 没有重复字符直接加字典
                alphaMap[s[currIndex]] = currIndex;
            } else { // 有重复字符，更新当前最大值，然后从字典删除部分字符
                int tempSize = currIndex - fromIndex;
                if (tempSize > result) {
                    result = tempSize;
                }

                int tempIndex = preAlpha->second;
                for (int i = fromIndex; i < tempIndex; ++i) {
                    alphaMap.erase(s[i]);
                }
                fromIndex = tempIndex + 1; // 更新下次对比长度的起始索引
                alphaMap[s[i]] = currIndex; // 更新当前字符的索引
            }
        }

        if (result < s.size() - fromIndex) { // 处理最后字符不重复情况
            result = s.size() - fromIndex;
        }
        return result;
    }
};