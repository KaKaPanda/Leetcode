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

    void bfs(vector<vector<bool>>& matrix, const int& beginIndex, const int& endIndex) {
        vector<vector<int>> paths1, paths2;
        bitset<600> crossed1, crossed2, itersect;
        paths1.emplace_back(vector<int>{beginIndex});
        paths2.emplace_back(vector<int>{endIndex});
        crossed1.set(beginIndex);
        crossed2.set(endIndex);

        while (!paths1.empty() && !paths2.empty()) { // 两边都不为孤岛
            vector<vector<int>> new_paths1, new_paths2;
            bitset<600> new_crossed1, new_crossed2;

            for (int i = 0; i < paths1.size(); ++i) {
                int curIndex = paths1[i].back();
                for (int j = 0; j < matrix.size(); ++j) {
                    if (matrix[curIndex][j] == true && crossed1[j] == false) {
                        new_paths1.emplace_back(paths1[i]);
                        new_paths1[new_paths1.size()-1].emplace_back(j);
                        new_crossed1.set(j); // 下一次循环加入字典进行剪枝
                    }
                }
            }

            paths1 = new_paths1;
            crossed1 |= new_crossed1;
            intersect = crossed1 & crossed2;
            if (intersect.count() > 0) break;

            for (int i = 0; i < paths2.size(); ++i) {
                int curIndex = paths2[i].back();
                for (int j = 0; j < matrix.size(); ++j) {
                    if (matrix[curIndex][j] == true && crossed2[j] == false) {
                        new_paths2.emplace_back(paths2[i]);
                        new_paths2[new_paths2.size()-1].emplace_back(j);
                        new_crossed2.set(j); // 下一次循环加入字典进行剪枝
                    }
                }
            }

            
            paths2 = new_paths2;
            crossed2 |= new_crossed2;
            intersect = crossed1 & crossed2;
            if (intersect.count() > 0) break;
        }

        for (int i = 0; i < intersect.size(); ++i) {
            if (intersect[i] == false) continue;
            for (int l = 0; l < paths1.size(); ++l) {
                if (paths1[l].back() != i) continue;
                for (int r = 0; r < paths2.size(); ++r) {
                    if (paths2[r].back() != i) continue;
                    shortest_paths.emplace_back(paths1[l]);
                    std::copy(paths2[r].rbegin()+1, paths2[r].rend(), std::back_inserter(shortest_paths.back()));
                }
            }
        }
    }

    void transPath2Ladder(const vector<string>& wordList) {
        for (auto &path : shortest_paths) {
            vector<string> ladder;
            for (auto &index : path) {
                ladder.emplace_back(wordList[index]);
            }
            shortest_ladder.emplace_back(ladder);
        }
    }

    vector<vector<int>> shortest_paths;
    vector<vector<string>> shortest_ladder;

    // 由于本题起点和终点固定，所以可以从起点和终点同时开始进行双向广度优先搜索，可以进一步降低时间复杂度
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int wc = wordList.size();
        if (wc == 0 || beginWord == endWord) return shortest_ladder;

        int beginIndex = wc, endIndex = -1;
        wordList.push_back(beginWord); // 将首元素压入
        vector<vector<bool>> matrix = vector<vector<bool>>(wc+1, vector<bool>(wc+1, false)); // 建图

        for (int i = 0; i <= wc; ++i) {
            if (wordList[i] == endWord) endIndex = i;
            for (int j = i+1; j <= wc; ++j) {
                if (checkLadder(wordList[i], wordList[j])) {
                    matrix[i][j] = true;
                    matrix[j][i] = true;
                }
            }
        }
        if (endIndex == -1) return shortest_ladder; // 终点不存在直接返回

        bfs(matrix, beginIndex, endIndex); // 广度优先搜索
        transPath2Ladder(wordList);
        return shortest_ladder;
    }
};