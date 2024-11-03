class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;

        // 这里用double类型，否则会超出数值范围
        vector<double> maxV = vector<double>(sz, 1); // 记录以i为结束的子数组最大值
        vector<double> minV = vector<double>(sz, 1); // 记录以i为结束的子数组最小值
        maxV[0] = minV[0] = nums[0];
        for (int i = 1; i < sz; ++i) {
            maxV[i] = max(double(nums[i]), max(maxV[i-1]*nums[i], minV[i-1]*nums[i]));
            minV[i] = min(double(nums[i]), min(maxV[i-1]*nums[i], minV[i-1]*nums[i]));
        }
        return *max_element(maxV.begin(), maxV.end());
    }
};