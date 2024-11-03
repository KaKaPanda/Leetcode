class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;

        int max_profit = 0;
        int min_value = prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < min_value) {
                min_value = prices[i]; // 更新最小值
            } else {
                max_profit = max(max_profit, prices[i]-min_value); // 更新最大利润
            }
        }
        return max_profit;
    }
};