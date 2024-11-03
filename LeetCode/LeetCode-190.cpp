class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret;
        for (int i = 0; i < 32; ++i) {
            ret <<= 1;
            if (n & 0x01) {
                ret += 1;
            }
            n >>= 1;
        }
        return ret;
    }
};