class Solution {
public:
    vector<int> grayCode(int n) { // 规律推导: 都是按上一个的序列加0 -> 上一个的逆序列加1
        // 0
        // 1

        // 00 01
        // 11 10

        // 000 001 011 010
        // 110 111 101 100

        // 0000 0001 0011 0010 0110 0111 0101 0100  
        // 1100 1101 1111 1110 1010 1011 1001 1000 
        
        if (n <= 0) return vector<int>{};
        vector<int> res = vector<int>(pow(2, n), 0); // 预分配空间

        for (int loop = 1; loop <= n; ++loop) {
            if (loop == 1) {
                res[1] = 1;
                continue;
            }

            int edge = pow(2, loop-1);
            for (int i = edge-1, j = edge; i >= 0 ; --i, ++j) {
                int high_bit = 1 << (loop-1);
                res[j] = res[i] | high_bit; // 按位或运算
            }
        }
        return res;
    }
};