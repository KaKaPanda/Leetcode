class Solution {
private:
    vector<vector<int>> skyline;

    struct Comparision {
        bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
            return (a.first == b.first) ? (a.second > b.second) : (a.first > b.first); // 最小堆
        }
    };

    void AppendSkyline(const int& start, const int& height) {
        if (skyline.empty()) { // 没有元素直接加入
            skyline.emplace_back(vector<int>{start, height});;
        } else if (skyline.back()[0] == start) { // 天际线起始端点一样，更新高度
            skyline.back()[1] = max(skyline.back()[1], height);
        } else if (skyline.back()[0] <= start) { // 天际线起始端点不小于已有端点，且高度不重合
            skyline.emplace_back(vector<int>{start, height});
        }
        if (skyline.size() > 1 && skyline[skyline.size()-2][1] == skyline.back()[1]) { // 检查末尾两元素高度是否重合
            skyline.pop_back();
        }
    }

    int GetOverHeight(priority_queue<pair<int, int>, vector<pair<int, int>>, Comparision> pq, int index) {
        int height = 0;
        while (pq.top().first >= index && pq.top().second != 0) {
            height = max(height, pq.top().second);
            pq.pop();
        }
        return height;
    }

public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) { // buildings 已经按左边界排好序

        std::priority_queue<pair<int, int>, vector<pair<int, int>>, Comparision> pq; // 优先队列，存放右边界和高度
        pq.push(pair<int, int>{INT_MAX, 0});                                         // 压入地平线
        buildings.emplace_back(vector<int>{INT_MAX, INT_MAX, 0});                    // 压入尾元素

        int cur_height = 0; // 记录当前对应的最大高度
        for (int i = 0; i < buildings.size(); ++i) {
            vector<int>& cur_build = buildings[i];
            if (cur_build.size() != 3) continue;
            
            while (pq.top().first <= cur_build[0] && pq.top().second != 0) {    // 处理优先队列中的右边界
                if (pq.top().second < cur_height) {                             // 建筑被当前高度被遮挡，跳过
                    pq.pop(); continue; 
                } else {
                    int right = pq.top().first; pq.pop();   // 拿到当前高度的右边界，作为新天际线左端点
                    int height = GetOverHeight(pq, right);  // 在剩余队列中查找覆盖当前端点的最大高度
                    if (right == cur_build[0]) {            // 需要跟当前建筑的高度进行对比
                        height = max(height, cur_build[2]);
                    }
                    AppendSkyline(right, height);           // 添加新天际线
                    cur_height = height;                    // 更新最大高度
                }
            }
            if (pq.top().second == 0) cur_height = 0;       // 队列中没有实体建筑，高度置零

            if (cur_height > cur_build[2]) { }              // 当前建筑被遮挡, 无需新增天际线
            else {
                AppendSkyline(cur_build[0], cur_build[2]);
                cur_height = cur_build[2];
            }
            pq.push({cur_build[1], cur_build[2]});          // 右边界放到PQ后续循环处理
        }
        return skyline;
    }
};