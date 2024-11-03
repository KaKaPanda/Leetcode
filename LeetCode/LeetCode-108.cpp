/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* subSortedArrayToBST(const vector<int>& nums, int i, int j) {
        TreeNode* head = new TreeNode();
        if (i > j) return head;

        int mid_index = (i + j) / 2;
        int left_len = mid_index - i;
        int right_len = j - mid_index;
        head->val = nums[mid_index];

        if (left_len > 0) {
            TreeNode* left_tree = subSortedArrayToBST(nums, i, i+left_len-1);
            head->left = left_tree;
        }
        if (right_len > 0) {
            TreeNode* right_tree = subSortedArrayToBST(nums, mid_index+1, j);
            head->right = right_tree;
        }
        return head;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return subSortedArrayToBST(nums, 0, nums.size()-1);
    }
};