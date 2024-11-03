class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;

        int word_count = 0;
        int remainWidth = maxWidth;

        for (int i = 0; i < words.size(); i+=word_count) {
            word_count = 0;
            remainWidth = maxWidth;
            stringstream ss;
            if (maxWidth < words[i].size()) break;

            while (i+word_count < words.size() && remainWidth >= int(words[i+word_count].size())) { // 注意这里会有类型隐式转换
                remainWidth -= words[i+word_count].size() + 1; // 为后面单词预留空格
                ++word_count;
            }
            int space_count = word_count + remainWidth; // 计算这一行所有空格

            if (word_count == 1) { // 单词独占一行
                res.push_back(words[i] + string(space_count, ' '));
                continue;
            }

            int space_even = space_count / (word_count - 1); // 计算平均空格数
            int space_plus = space_count % (word_count - 1); // 计算多余空格数

            bool isLastLine = (i+word_count >= words.size()); // 判断是否最后一行
            for (int j = i; j < i + word_count && j < words.size(); ++j) {
                ss << words[j];
                int spaces = 0;
                if (j != i + word_count - 1) { // 不是最后一个单词
                    bool padding = (space_plus-- > 0)? true : false;
                    spaces = (isLastLine)? 1 : space_even + padding; // 最后一行单词之间不插入额外的空格
                } else {
                    spaces = (isLastLine)? maxWidth - ss.str().size() : 0; // 最后一行的最后一个单词后面填充空格
                }
                if (spaces > 0) {
                    ss << string(spaces, ' ');
                }
            }

            res.push_back(ss.str());
        }

        return res;
    }
};