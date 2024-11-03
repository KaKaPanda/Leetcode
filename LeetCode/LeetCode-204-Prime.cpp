class Solution {
public:
    // 2 3 5 7 11 13 17 19 23 27 29 31 37 
    int countPrimes(int n) { // 埃氏筛
        int cnt = 0;
        vector<bool> isPrime(n+1, true);
        
        for (int i = 2; i < n; ++i) {
            if (isPrime[i] != 1) continue;

            ++cnt;

            for (int j = 2; i*j < n; ++j) {
                isPrime[i*j] = false;
            } 
        }
        return cnt;
    }
};