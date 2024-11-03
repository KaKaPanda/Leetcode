class Solution {
public:
    int numTrees(int n) { // Catalan: 序号从0开始: 1, 1, 2, 5, 14, 42
        long long res = 1;
        for (int i = 0; i < n; ++i) {
            res = res * 2 * (2*i + 1) / (i + 2);
        }
        return res;
    }
};