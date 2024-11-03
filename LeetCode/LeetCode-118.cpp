class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        
        while (numRows--) {
            if (res.empty()) {
                res.emplace_back(vector<int>{1});
                continue;
            }

            vector<int> next_vec = res.back();
            
            for (int i = next_vec.size()-1; i >= 1; --i) {
                next_vec[i] += next_vec[i-1];
            }
            next_vec.emplace_back(1);
            res.emplace_back(next_vec);
        }
        return res;
    }
};