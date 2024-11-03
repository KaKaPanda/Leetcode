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
    // Morris 遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;

        TreeNode *node = root, *predecessor = nullptr;
        while (node != nullptr) {
            if (node->left != nullptr) {
                predecessor = node->left;
                while (predecessor->right != nullptr && predecessor->right != node) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr) {
                    res.push_back(node->val);
                    predecessor->right = node;
                    node = node->left;
                } else {
                    predecessor->right = nullptr;
                    node = node->right;
                }
            } else {
                res.push_back(node->val);
                node = node->right;
            }

        }
        return res;
    }


    // 迭代解法
    /* vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;

        stack<TreeNode*> node_stk;
        node_stk.push(root);

        while (!node_stk.empty()) {
            TreeNode* node = node_stk.top();
            node_stk.pop();
            res.push_back(node->val);

            if (node->right != nullptr) {
                node_stk.push(node->right); // 先放入右节点
            }
            if (node->left != nullptr) {
                node_stk.push(node->left); // 再放入左节点
            }
        }
        return res;
    } */
};