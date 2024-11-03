class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) return false;

        std::unordered_set<int> num_window;

        for (int i = 0; i < nums.size(); ++i) {
            if (num_window.find(nums[i]) != num_window.end()) {
                return true;
            }

            num_window.insert(nums[i]);
            if (num_window.size() > k) {
                num_window.erase(nums[i-k]);
            }
        }
        return false;
    }
};