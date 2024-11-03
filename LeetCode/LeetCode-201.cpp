class Solution {
public:
    // 给你两个整数 left 和 right ，表示区间 [left, right] ，
    // 返回此区间内所有数字 按位与 的结果（包含 left 、right 端点）。
    int rangeBitwiseAnd(int m, int n) {
        int diff = m ^ n;
        for(int i = 0; i < sizeof(int)*8; ++i){
            diff |= (diff >> 1);
        }
        return n & (~diff);
    }
};