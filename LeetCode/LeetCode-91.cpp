class Solution {
public:
    int numDecodings(string s) {  // 需要考虑后导为0, 例如2101输出为1; 同时需要考虑多个0
        if (s.size() == 0 || s[0] == '0') return 0;  // 特殊情况直接返回

        vector<int> step = vector<int>(s.size(), 0);
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0) {
                step[i] = 1; // 第一个数字非0, 直接取1
            }
            else if (s[i-1] == '0') { // 前导为0，res不变
                if (s[i] == '0') return 0; // 连续多个0直接返回
                else step[i] = step[i-1];
            }
            else if (s[i-1] == '1') {
                if (s[i] == '0') { 
                    step[i] = step[i-1];
                } else {
                    if (i+1 < s.size() && s[i+1] == '0') { // 后导为0, res不变
                        step[i] = step[i-1];
                    } else {
                        step[i] += step[i-1];
                        if (i >= 2) step[i] += step[i-2];
                        else step[i] += 1; // 注意这里需要+1
                    }
                }
            }
            else if (s[i-1] == '2') {
                if (s[i] == '0') {
                    step[i] = step[i-1];
                } else if (s[i] <= '6') {
                    if (i+1 < s.size() && s[i+1] == '0') { // 后导为0, res不变
                        step[i] = step[i-1];
                    } else {
                        step[i] += step[i-1];
                        if (i >= 2) step[i] += step[i-2];
                        else step[i] += 1; // 注意这里需要+1
                    }
                } else {
                    step[i] = step[i-1];
                }
            }
            else if (s[i-1] > '2') {
                if (s[i] == '0') {
                    return 0;
                } else {
                    step[i] = step[i-1];
                }
            }
        }
        return step[s.size() - 1];
    }
};