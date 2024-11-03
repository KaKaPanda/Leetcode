class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = prices[0], sell1 = 0;
        int buy2 = prices[0], sell2 = 0;
        
        for (int i = 1; i < prices.size(); ++i) {
            buy1 = min(buy1, prices[i]); // 以最低价买入
            sell1 = max(sell1, prices[i]-buy1); // 高价差卖出
            buy2 = min(buy2, prices[i]-sell1); // 低价买入，同时把第一次收入计算在内
            sell2 = max(sell2, prices[i]-buy2); // 高价差卖出
        }
        return sell2;
    }
};