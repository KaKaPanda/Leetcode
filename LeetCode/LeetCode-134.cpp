class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) { // 需要动态规划，嵌套循环会超时
        int begin_index = -1, even_gas = 0, real_gas = 0;
        if (gas.size() != cost.size()) return begin_index;

        for (int i = 0; i < gas.size(); ++i) {
            even_gas += gas[i] - cost[i];
            real_gas += gas[i] - cost[i];
            if (real_gas >= 0 && begin_index == -1) {
                begin_index = i;
            }
            if (real_gas < 0) {
                begin_index = -1;
                real_gas = 0;
            }
        }
        return (even_gas >= 0)? begin_index : -1;
    }
};