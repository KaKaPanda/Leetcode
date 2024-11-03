class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int leftIndex1 = 0;
        int leftIndex2 = 0;
        int rightIndex1 = nums1.size() - 1;
        int rightIndex2 = nums2.size() - 1;

        int smallNum, largeNum = 0;

        while(leftIndex1 <= rightIndex1 || leftIndex2 <= rightIndex2) { 
        
            // 从左侧取两个数组较小的数字
            if (leftIndex1 <= rightIndex1 && leftIndex2 <= rightIndex2) {
                if (nums1[leftIndex1] < nums2[leftIndex2]) {
                    smallNum = nums1[leftIndex1];
                    ++leftIndex1;
                } else {
                    smallNum = nums2[leftIndex2];
                    ++leftIndex2;
                }
            } else if (leftIndex1 <= rightIndex1 && leftIndex2 > rightIndex2) {
                smallNum = nums1[leftIndex1];
                ++leftIndex1;
            } else if (leftIndex1 > rightIndex1 && leftIndex2 <= rightIndex2) {
                smallNum = nums2[leftIndex2];
                ++leftIndex2;
            }

            // 从右侧取两个数组较大的数字
            if (leftIndex1 <= rightIndex1 && leftIndex2 <= rightIndex2) {
                if (nums1[rightIndex1] > nums2[rightIndex2]) {
                    largeNum = nums1[rightIndex1];
                    --rightIndex1;
                } else {
                    largeNum = nums2[rightIndex2];
                    --rightIndex2;
                }
            } else if (leftIndex1 <= rightIndex1 && leftIndex2 > rightIndex2) {
                largeNum = nums1[rightIndex1];
                --rightIndex1;
            } else if (leftIndex1 > rightIndex1 && leftIndex2 <= rightIndex2) {
                largeNum = nums2[rightIndex2];
                --rightIndex2;
            } else { // 处理数据被取完的情况
                largeNum = smallNum;
            }

        }

        return (largeNum + smallNum)/2.0;
    }
};