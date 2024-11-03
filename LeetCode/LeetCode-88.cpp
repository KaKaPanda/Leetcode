class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;

        for (int i = m + n; i > 0; --i) { // 从后面向前推进
            if (m == 0 && n != 0) {
                nums1[i-1] = nums2[n-1];
                --n;
            } else if (m != 0 && n == 0) {
                break;
            } else if (nums1[m-1] < nums2[n-1]) {
                nums1[i-1] = nums2[n-1];
                --n;
            } else {
                nums1[i-1] = nums1[m-1];
                --m;
            }
        }
    }
};