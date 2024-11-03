class Solution {
public:
    vector<vector<int>> getSubCombination(vector<int>& candidates, int target, int ind) { // 通过索引来限制不重复使用同一元素
        vector<vector<int>> res;
        if (candidates.size() == 0 || target <= 0) return res;

        for (int i = ind; i < candidates.size(); ++i) {
            if (i > 0 && i > ind && candidates[i] == candidates[i - 1]) {
                continue; // 通过跳过后续相同元素来去重, 这里只会跳过当前函数的循环，对递归函数中的循环不影响
            }
            int candidate = candidates[i];
            if (candidate == target) {
                res.push_back(vector<int>{candidate});
                return res;
            } else {
                vector<vector<int>> sub_res = getSubCombination(candidates, target - candidate, i+1);
                for (int j = 0; j < sub_res.size(); ++j) {
                    if (j > 0 && sub_res[j] == sub_res[j-1]) {
                        continue;
                    }
                    if (sub_res[j].size() > 0 && candidate <= sub_res[j].back()) {
                        sub_res[j].push_back(candidate);
                        res.push_back(sub_res[j]);
                    }
                }
            }
        }
        return res;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) { // candidates中有重复元素，解集不能包含重复的组合 
        std::sort(candidates.begin(), candidates.end()); // 通过预先排序来去重
        return getSubCombination(candidates, target, 0);
    }
};