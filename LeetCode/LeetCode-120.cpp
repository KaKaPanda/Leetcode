class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty()) return 0;

        vector<int> path_sum_vec;
        path_sum_vec.push_back(triangle[0][0]);

        for (int i = 1; i < triangle.size(); ++i) {
            path_sum_vec.push_back(path_sum_vec.back());
            for (int j = path_sum_vec.size()-1; j >= 1; --j) {
                path_sum_vec[j] = min(path_sum_vec[j], path_sum_vec[j-1]) + triangle[i][j];
            }
            path_sum_vec[0] += triangle[i][0];
        }

        int min_ans = INT_MAX;
        for (int i = 0; i < path_sum_vec.size(); ++i) {
            if (path_sum_vec[i] < min_ans) {
                min_ans = path_sum_vec[i];
            }
        }
        return min_ans;
    }
};