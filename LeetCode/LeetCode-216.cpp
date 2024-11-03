class Solution {
private:
    std::bitset<10> num_mask;
    vector<vector<int>> res;

    void Mask2Combination(const std::bitset<10>& num_mask) {
        vector<int> combination;
        for (int i = 1; i <=9; ++i) {
            if (num_mask.test(i)) {
                combination.emplace_back(i);
            }
        }
        res.emplace_back(combination);
    }

    void dfs(int start, int k, int n) {
        if (start + k > 10) return; // 数字不够用
        if (k == 1) {
            if (n <= 0 || n > 9) return; // 超出范围
            if (num_mask.test(n) == false) {
                num_mask.set(n);
                Mask2Combination(num_mask);
                num_mask.reset(n);
            }
        } else {
            for (int i = start; i <= 9; ++i) {
                if (n <= 2 * i) break; // 超出范围 或者 索引重复
                num_mask.set(i);
                dfs(i+1, k-1, n-i);
                num_mask.reset(i);
            }
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k <= 0 || k > 9) return res;

        int minV = 0, maxV = 0;
        for (int i = 1, j = 9; i <= k; ++i, --j) {
            minV += i;
            maxV += j;
        }
        if (n < minV || n > maxV) return res;

        dfs(1, k, n);

        return res;
    }
};