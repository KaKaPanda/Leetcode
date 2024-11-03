class Solution {
public:
    string convert(string s, int numRows) {
        // 找出每一行的步长规律, 假设总行数N, 当前行数 n=0,1,2,...
        // 0: 2*(N-1)
        // 1: 2*(N-2), 2*1
        // 2: 2*(N-3), 2*2
        // ...
        // n: 2*(N-n-1), 2*n
        
        // 注意处理特殊情况
        if (numRows <= 1 || s.size() <= 1) {
            return s;
        }

        string result;
        int cur_index = 0;

        for (int i = 0; i < numRows; ++i) { // 按行数循环
            int pace = i;
            if (pace < s.size()) { // 加入首个字母
                result += s[pace];
            }
            while (pace < s.size()) {
                int temp_pace1 = 2*(numRows-i-1);
                if (temp_pace1 > 0 && pace + temp_pace1 < s.size()) {
                    result += s[pace + temp_pace1];
                }
                int temp_pace2 = 2*i;
                if (temp_pace2 > 0 && pace + temp_pace1 + temp_pace2 < s.size()) {
                    result += s[pace + temp_pace1 + temp_pace2];
                }
                pace += temp_pace1 + temp_pace2;
            }
        }
        return result;
    }
};