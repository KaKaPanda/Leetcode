class Solution {
public:
    int jump(vector<int>& nums) { // [1,2,1,1,1] 预期3步
        if (nums.size() <= 1) return 0;

        vector<int> step(nums.size(), INT_MAX);
        step[0] = 0;

        int max_edge = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int cur_step = step[i];  // 从当前索引取出步数
            int edge = i + nums[i];
            if (max_edge < edge) {
                max_edge = edge;
            }
            for (int j = i + 1; j <= edge && j < nums.size(); ++j) {
                if (cur_step < step[j]) {
                    step[j] = cur_step + 1;
                }
            }
        }

        return step[nums.size() - 1];
    }
};