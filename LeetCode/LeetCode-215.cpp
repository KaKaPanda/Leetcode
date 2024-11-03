class Solution {
private:
    struct Comparison {
        bool operator() (const int& a, const int& b) const {
            return a > b; // 最小堆
        }
    };

public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, vector<int>, Comparison> pq;

        for (int i = 0; i < k; ++i) pq.push(nums[i]);
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] <= pq.top()) continue;
            pq.push(nums[i]);
            pq.pop();
        }
        
        return pq.top();
    }
};