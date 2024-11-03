class Solution {
public:
    // [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 
    int nthUglyNumber(int n) {
        if (n <= 0) return -1;

        std::vector<int> uglyVec{1};
        int curr2 = 0, curr3 = 0, curr5 = 0;

        while (uglyVec.size() != n) {
            int newUgly = min(min(uglyVec[curr2]*2, uglyVec[curr3]*3), uglyVec[curr5]*5);
            uglyVec.emplace_back(newUgly);

            while (uglyVec[curr2]*2 <= newUgly) ++curr2;
            while (uglyVec[curr3]*3 <= newUgly) ++curr3;
            while (uglyVec[curr5]*5 <= newUgly) ++curr5;
        }
        return uglyVec[n-1];
    }
};