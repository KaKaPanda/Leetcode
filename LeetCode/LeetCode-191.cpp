class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while (n) {
            if (n & 0x01) cnt++;
            n >>= 1;
        }
        return cnt;
    }
};