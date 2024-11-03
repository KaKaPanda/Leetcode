class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long raw = x; // 使用 long long 来避免 int 超出范围
        long long res = 0;
        while (x != 0) {
            int temp = x % 10;
            x /= 10;
            res = res * 10 + temp;
        }
        return res == raw;
    }
};