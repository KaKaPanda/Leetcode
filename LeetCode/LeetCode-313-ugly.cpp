class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int sz = primes.size();
        if (n <= 0 || sz == 0) return -1;

        vector<int> currIdx(sz, 0);
        vector<int> uglyVec{1};

        while (uglyVec.size() < n) {
            long long newUgly = INT_MAX;
            for (int i = 0; i < sz; ++i) {
                newUgly = min(newUgly, (long long)(primes[i]) * uglyVec[currIdx[i]]);
            }

            uglyVec.emplace_back(newUgly);
            for (int i = 0; i < sz; ++i) {
                while ((long long)(primes[i]) * uglyVec[currIdx[i]] <= newUgly) {
                    ++currIdx[i];
                }
            }
        }
        return uglyVec.back();
    }
};