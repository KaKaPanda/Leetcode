class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n == 0) return 0;

        vector<vector<bool>> matrix = vector<vector<bool>>(n, vector<bool>(n, false));
        for (int i = n-1; i >= 0; --i) {  // i的循环是逆序的，因为迭代公式中先用到了matrix[i+1]
            for (int j = i; j < n; ++j) {
                if (i+1 >= j) {
                    matrix[i][j] = s[i] == s[j];
                } else {
                    matrix[i][j] = matrix[i+1][j-1] && (s[i] == s[j]); // 动态规划求解, 否则过于耗时
                }
            }
        }

        int step = 0;
        std::unordered_set<int> cover_index, cur_index, nex_index;
        cover_index.insert(0);
        cur_index.insert(0);

        while (!cur_index.empty()) {  // 这里用到贪婪算法遍历图来求解，实际上可以初始化 vector<int> f(n, INT_MAX); 动态更新来求解更优
            for (auto & index : cur_index) { // 遍历当前索引集
                for (int j = n-1; j >= index ; --j) { // 检索可能跳到的下一个索引
                    if (cover_index.find(j+1) != cover_index.end()) continue; // 说明之前检索过(j+1)，步数肯定更大直接跳过
                    if (matrix[index][j] == true) {
                        if (j+1 == n) return step;
                        nex_index.insert(j+1);
                    }
                }
            }
            ++step;
            cover_index.insert(nex_index.begin(), nex_index.end());
            cur_index = nex_index;
            nex_index.clear(); // 需要清空
        }
        return step;
    }
};