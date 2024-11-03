class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0) {
                nums[i] = N+1; // 为了将-1作为索引标记，先将负数和0转换为N+1
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == -1 || nums[i] > N) {
                continue;
            }

            int next = nums[i];
            while (next > 0 && next <= N) {
                int temp = nums[next-1]; // 将出现过1-N的数字索引置为-1
                nums[next-1] = -1;
                next = temp;
            }
        }

        for (int i = 0; i < nums.size(); ++i) { // 找到第一个值不为-1的索引
            if (nums[i] != -1) {
                return i + 1;
            }
        }
        return N + 1;
    }
};