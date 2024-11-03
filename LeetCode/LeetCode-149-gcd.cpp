class Solution {
private:
    int gcd(int a, int b) { // a、b 符号不影响结果
        return (b == 0)? a : gcd(b, a%b);
    }
public:
    int maxPoints(vector<vector<int>>& points) { // 枚举直线 + 枚举统计
        int n = points.size();
        if (n == 0) return 0;

        int ans = 1;
        for (int i = 0; i < n; ++i) {
            map<string, int> key_map;
            int max_cnt = 0;
            for (int j = i+1; j < n; ++j) {
                int a = points[i][0] - points[j][0];
                int b = points[i][1] - points[j][1];
                int k = gcd(a, b);
                string key = to_string(a/k) + "_" + to_string(b/k); // a、b 符号不影响结果
                key_map[key]++;
                max_cnt = max(max_cnt, key_map[key]);
            }
            ans = max(ans, max_cnt+1); // 这里 max_cnt 要加一
        }
        return ans;
    }
};