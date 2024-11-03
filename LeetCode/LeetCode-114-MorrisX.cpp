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
    void flatten(TreeNode* root) { // 先序遍历展开链表
        TreeNode* node = root;

        while (node != nullptr) {
            if (node->left != nullptr) {
                TreeNode* predecessor = node->left;
                while (predecessor->left != nullptr && predecessor->right == nullptr) {
                    predecessor = predecessor->left; // 没有遇到右叶子节点一直向左走
                }
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right; // 之后一直向右走
                }
                predecessor->right = node->right; // 将先序遍历的前后节点连接起来

                TreeNode* pre_node = node;
                node = node->left;                // node先向左边步进
                pre_node->right = pre_node->left; // 将左树挂在右连接, 这里会自动修正连接
                pre_node->left = nullptr;         // 断开左连接

            } else {
                node = node->right; // 没有左节点向右走, 这里会经过之前修改过的右连接
            }
        }
        return;
    }
};