class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool merged = false;
        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); ++i) {
            // if (intervals[i].size() != 2) continue;
            bool intersect = false;
            vector<int> cur = intervals[i];
            
            if (merged) {
                res.push_back(cur);
                continue;  // 已合并直接跳过后面逻辑
            }
            
            intersect = !((cur[0] > newInterval[1] && cur[1] > newInterval[1]) || // 注意两个区间相交的条件
                          (cur[0] < newInterval[0] && cur[1] < newInterval[0]));

            if (!intersect) {
                if (newInterval[1] < cur[0]) { // 不需要合并区间直接插入
                    merged = true;
                    res.push_back(newInterval);
                }
                res.push_back(cur); // 同时插入下一个区间
                continue;
            }

            // 需要合并区间
            while (intersect) {
                merged = true;
                if (cur[0] < newInterval[0]) {
                    newInterval[0] = cur[0];
                }
                if (cur[1] > newInterval[1]) {
                    newInterval[1] = cur[1];
                }
                if (++i >= intervals.size()) {
                    break;
                } else {
                    cur = intervals[i];
                    intersect = !((cur[0] > newInterval[1] && cur[1] > newInterval[1]) || // 注意两个区间相交的条件
                                  (cur[0] < newInterval[0] && cur[1] < newInterval[0]));
                }
                if (!intersect) --i;
            }
            res.push_back(newInterval);
        }

        if (!merged) { // 处理intervals为空，或者最后未插入的情况
            merged = true;
            res.push_back(newInterval);
        }
        return res;
    }
};