class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::string ans("0");

        std::sort(nums.rbegin(), nums.rend(), [](const int& n1, const int& n2) {
            return to_string(n1) + to_string(n2) < to_string(n2) + to_string(n1);
        });

        for (auto & num : nums) {
            if (ans == "0") ans = "";
            ans += to_string(num);
        }
        return ans;
    }
};