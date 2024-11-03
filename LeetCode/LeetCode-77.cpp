class Solution {
public:
    vector<vector<int>> subCombine(const vector<int>& vec, int st, int k) {
        vector<vector<int>> res;
        if (k <= 0) return res;

        for (int i = st; i + k - 1 < vec.size(); ++i) { // +(k-1) 表示剩余元素够用
            int member = vec[i];
            vector<vector<int>> sub_res = subCombine(vec, i+1, k-1);
            if (sub_res.size() == 0) {
                res.emplace_back(vector<int>{member});
            } else {
                for (int j = 0; j < sub_res.size(); ++j) {
                    sub_res[j].push_back(member);
                    res.push_back(sub_res[j]);
                }
            }
        }
        return res;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> vec;
        for (int i = n; i >= 1; --i) {
            vec.push_back(i);
        }

        vector<vector<int>> res;
        if (n == 0 || n < k) return res;

        return subCombine(vec, 0, k);
    }
};