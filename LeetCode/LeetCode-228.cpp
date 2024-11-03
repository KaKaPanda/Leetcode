class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) { // nums按升序排序
        vector<string> res;
        if (nums.empty()) return res;

        int left = nums[0], right = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == right + 1) {
                right++;
            } else {
                if (left == right) {
                    res.emplace_back(to_string(left));
                } else {
                    res.emplace_back(to_string(left) + "->" + to_string(right));
                }
                left = nums[i], right = nums[i];
            }
        }

        if (left == right) { // 注意处理末尾元素
            res.emplace_back(to_string(left));
        } else {
            res.emplace_back(to_string(left) + "->" + to_string(right));
        }
        return res;
    }
};