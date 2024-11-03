class Solution {
public:
    bool canMeasureWater(int x, int y, int z) { // 3, 5, 1
        if (x + y < z) return false;
        if (x == 0 || y == 0) return z == 0 || x + y == z;
        return z % gcd(x, y) == 0; //我们只需要找到 x, y 的最大公约数并判断 z 是否是它的倍数即可。
    }
};