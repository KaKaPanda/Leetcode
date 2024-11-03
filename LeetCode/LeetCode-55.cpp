class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> step(nums.size(), INT_MAX);
        step[0] = 1;

        for (int i = 0; i < nums.size(); ++i) {
            if (step[i] == INT_MAX) continue;

            int edge = i + nums[i];
            for (int j = i + 1; j < nums.size() && j <= edge; ++j) {
                step[j] = 1;
            }
        }
        return step[nums.size()-1] == 1;
    }
};