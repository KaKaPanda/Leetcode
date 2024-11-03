class Solution {
public:
    int climbStairs(int n) {
        // 1 : 1
        // 2 : 2
        // 3 : 3
        int n1 = 1, n2 = 1;
        for (int i = 2; i <= n; ++i) {
            int n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
        return n2;
    }
};