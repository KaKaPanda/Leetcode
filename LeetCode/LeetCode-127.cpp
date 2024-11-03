class Solution {
public:
    bool checkLadder(const string& str1, const string& str2) {
        if (str1.size() != str2.size()) return false;

        int diff_cnt = 0;
        for (int i = 0; i < str1.size(); ++i) {
            if (str1[i] != str2[i]) ++diff_cnt;
            if (diff_cnt > 1) return false;
        }
        return diff_cnt == 1;
    }

    int bfs(vector<vector<int>>& matrix, int beginIndex, int endIndex) {
        int depth = 1;
        set<int> indexes;
        set<int> nex_indexes;
        indexes.insert(beginIndex);

        while (!indexes.empty()) {
            ++depth;
            for (auto iter = indexes.begin(); iter != indexes.end(); ++iter) {
                for (int j = 0; j < matrix.size(); ++j) {
                    if (matrix[*iter][j] != 1) {
                        continue;
                    }

                    if (j == endIndex) {
                        return depth;
                    } else {
                        matrix[*iter][j] = 0;
                        matrix[j][*iter] = 0;
                        nex_indexes.insert(j);
                    }
                }
            }

            indexes = nex_indexes;
            nex_indexes.clear();
        }

        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) { // 广度优先搜索 + 优化建图
        int wc = wordList.size();
        if (wc == 0 || beginWord == endWord) return 0;

        int beginIndex = wc, endIndex = -1;
        wordList.push_back(beginWord); // 将首元素压入
        vector<vector<int>> matrix = vector<vector<int>>(wc+1, vector<int>(wc+1, 0)); // 建图

        for (int i = 0; i <= wc; ++i) {
            if (wordList[i] == endWord) endIndex = i;
            for (int j = i+1; j <= wc; ++j) {
                if (checkLadder(wordList[i], wordList[j])) {
                    matrix[i][j] = 1;
                    matrix[j][i] = 1;
                }
            }
        }

        if (endIndex == -1) return 0; // 终点不存在直接返回

        return bfs(matrix, beginIndex, endIndex); // 广度优先搜索
    }
};