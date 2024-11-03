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
    bool isBalancedSubTree(TreeNode* father, int& height) {
        if (father == nullptr) {
            height = 0;
            return true;
        }

        int left_height = 0, right_height = 0;
        if (father->left != nullptr) {
            if (!isBalancedSubTree(father->left, left_height)) {
                return false;
            }
        }
        if (father->right != nullptr) {
            if (!isBalancedSubTree(father->right, right_height)) {
                return false;
            }
        }

        height = max(left_height, right_height) + 1;
        return abs(left_height - right_height) <= 1;
    }

    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalancedSubTree(root, height);
    }
};