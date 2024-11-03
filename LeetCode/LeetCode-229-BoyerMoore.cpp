class Solution {
public:
    // 进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。
    vector<int> majorityElement(vector<int>& nums) {
        int element1 = 0, element2 = 0;
        int vote1 = 0, vote2 = 0;

        for (auto & num : nums) {
            if (vote1 != 0 && num == element1) { // 如果该元素为第一个元素，则计数加1
                ++vote1;
            } else if (vote2 != 0 && num == element2) { // 如果该元素为第二个元素，则计数加1
                ++vote2;
            } else if (vote1 == 0) { // 选择第一个元素
                element1 = num;
                ++vote1;
            } else if (vote2 == 0) { // 选择第二个元素
                element2 = num;
                ++vote2;
            } else { // 如果三个元素均不相同，则相互抵消1次
                --vote1;
                --vote2;
            }
        }

        vector<int> res;
        int cnt1 = 0, cnt2 = 0;
        for (auto & num :nums) {
            if (num == element1) ++cnt1;
            if (num == element2) ++cnt2;
        }
        if (cnt1 > nums.size()/3) res.emplace_back(element1);
        if (cnt2 > nums.size()/3 && element2 != element1) res.emplace_back(element2); // 注意排除全为0的情况
        return res;
    }
};