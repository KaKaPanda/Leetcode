class Solution {
public:
    int candy(vector<int>& ratings) {
        int sz = ratings.size();
        vector<int> candies_left = vector<int>(sz, 1);
        vector<int> candies_right = vector<int>(sz, 1);

        for (int i = 1; i < sz; ++i) { // 从左边遍历
            if (ratings[i-1] < ratings[i]) {
                candies_left[i] = candies_left[i-1] + 1; 
            }
        }
        for (int i = sz-2; i >= 0; --i) { // 从右边遍历
            if (ratings[i+1] < ratings[i]) {
                candies_right[i] = candies_right[i+1] + 1;

            }
        }

        int candies_count = 0;
        for (int i = 0; i < sz; ++i) {
            candies_count += max(candies_left[i], candies_right[i]); // 两边取最大
        }
        return candies_count;
    }
};

// 1 2 3 3 7 6 5 4 4 3 2 2 4 5
// 0 1 2 0 1 0 0 0 0 0 0 0 1 2
// 0 0 0 0 3 2 1 0 2 1 0 0 0 0
// 0 1 2 0 3 2 1 0 2 1 0 0 1 2