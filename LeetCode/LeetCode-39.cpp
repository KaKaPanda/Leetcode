class Solution {
public:
    vector<vector<int>> getSubCombination(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.size() == 0 || target <= 0) return res;

        for (int i = 0; i < candidates.size(); ++i) {
            int candidate = candidates[i];
            if (candidate == target) {
                res.push_back(vector<int>{candidate});
                return res;
            } else {
                vector<vector<int>> sub_res = getSubCombination(candidates, target - candidate);
                for (int j = 0; j < sub_res.size(); ++j) {
                    if (sub_res[j].size() > 0 && candidate <= sub_res[j].back()) { // 等于号表示可以重复使用
                        sub_res[j].push_back(candidate);
                        res.push_back(sub_res[j]);
                    }
                }
            }
        }
        return res;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) { // candidates中无重复元素，解集不能包含重复的组合 
        std::sort(candidates.begin(), candidates.end()); // 通过预先排序来去重
        return getSubCombination(candidates, target);
    }
};