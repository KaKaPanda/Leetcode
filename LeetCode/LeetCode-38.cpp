class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        if (n == 1) return "1";

        string res("1");
        for (int i = 2; i <= n; ++i) {
            stringstream ss("");
            for (int j = 0; j < res.size(); ++j) {
                char alpha = res[j];
                int count = 1;
                while(j + 1 < res.size() && res[j+1] == alpha) {
                    ++count;
                    ++j;
                }
                ss << count << alpha;
            }
            res = ss.str();
        }

        return res;
    }
};