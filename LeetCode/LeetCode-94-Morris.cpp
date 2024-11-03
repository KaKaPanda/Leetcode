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

// 1. 递归
// 2. 通过栈进行迭代
// 3. Morris 中序遍历

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* predecessor = new TreeNode();

        while (root != nullptr) {
            if (root->left != nullptr) {
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right; // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                }

                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                } else {
                    res.push_back(root->val);
                    predecessor->right = nullptr; // 说明左子树已经访问完了，我们需要断开链接
                    root = root->right;
                }
            } else { // 如果没有左孩子，则直接访问右孩子
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
