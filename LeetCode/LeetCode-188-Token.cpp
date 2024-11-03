class Solution {
public:
    // 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
    // 也就是说，你最多可以买 k 次，卖 k 次。

    int maxProfit(int k, vector<int>& prices) {
        int sz = prices.size();
        if (sz == 0 || k <= 0) return 0;

        vector<int> brought(k, prices[0]);
        vector<int> profit(k, 0);
        
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < k; ++j) {
                if (j == 0) {
                    brought[j] = min(brought[j], prices[i]); // 以最低价买入
                } else {
                    brought[j] = min(brought[j], prices[i] - profit[j-1]); // 低价买入，同时把第一次收入计算在内
                }
                profit[j] = max(profit[j], prices[i] - brought[j]); // 高价差卖出
            }
        }
        return *max_element(profit.begin(), profit.end());
    }
};