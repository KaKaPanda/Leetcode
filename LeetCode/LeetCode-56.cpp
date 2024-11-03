class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) { // 合并区间，注意第一个区间和最后一个区间
        vector<vector<int>> res;
        std::sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].size() != 2) continue;
            if (i == intervals.size()-1) {
                res.push_back(intervals[i]); // 最后一个元素没有被合并直接推入
                break;
            }

            vector<int> cur = intervals[i];
            while (i+1 < intervals.size() && cur[1] >= intervals[i+1][0]) {
                if (cur[1] < intervals[i+1][1]) {
                    cur[1] = intervals[i+1][1];
                }
                ++i;
            }
            res.push_back(cur);
        }
        return res;
    }
};