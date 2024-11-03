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
    void recoverTree(TreeNode* root) { // 中序遍历
        TreeNode *x = nullptr, *y = nullptr; // x 为第一个乱序元素, y 为最后一个乱序元素
        TreeNode *predecessor = nullptr, *pre = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                } else {
                    
                    if (pre != nullptr && pre->val > root->val) {
                        if (x == nullptr) {
                            x = pre;
                        }
                        y = root;
                    }
                    pre = root;

                    predecessor->right = nullptr;
                    root = root->right;
                }
            } else {

                if (pre != nullptr && pre->val > root->val) {
                    if (x == nullptr) {
                        x = pre;
                    }
                    y = root;
                }
                pre = root;

                root = root->right;
            }
        }

        int temp = x->val;
        x->val = y->val;
        y->val = temp;
        return;
    }
};