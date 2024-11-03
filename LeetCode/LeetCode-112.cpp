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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }

        bool left_path_succ = false, right_path_succ = false;
        if (root->left != nullptr) {
            left_path_succ = hasPathSum(root->left, targetSum - root->val);
        }
        if (root->right != nullptr) {
            right_path_succ = hasPathSum(root->right, targetSum - root->val);
        }
        return left_path_succ || right_path_succ;
    }
};