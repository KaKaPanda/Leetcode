class Solution {
public:
    bool detectCapitalUse(string word) {
        int first = 0;
        int count = 0;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                if (i == 0) first = true;
                ++count;
            }
        }
        return count == 0 || count == word.size() || count == 1 && first;
    }
};