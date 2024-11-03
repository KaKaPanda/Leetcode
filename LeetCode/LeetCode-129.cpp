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
    int sumNumbers(TreeNode* root) { // 本质是一个后序遍历, 解法比较复杂, 也可以用dfs来求解
        if (root == nullptr) return 0;

        std::stack<TreeNode*> node_stack;
        node_stack.push(root);
        int sum = 0;
        int path_val = root->val;
        
        while (!node_stack.empty()) {
            TreeNode* node = node_stack.top();
            while (node->left != nullptr) { // 只要左树不为空，循环压入
                node_stack.push(node->left);
                path_val = 10 * path_val + node->left->val;
                TreeNode* next_node = node->left;
                node->val = -1; // 标记为非叶子节点
                node->left = nullptr; // 剪掉原来的连接
                node = next_node;
            }
            // 左树为空，但是右树不为空
            if (node->right != nullptr) {
                node_stack.push(node->right);
                path_val = 10 * path_val + node->right->val;
                TreeNode* next_node = node->right;
                node->val = -1; // 标记为非叶子节点
                node->right = nullptr; // 剪掉原来的连接
                node = node->right;
            }
            // 左树右树都为空
            else if (node->right == nullptr) {
                if (node->val != -1) {
                    sum += path_val; // 非叶子节点才累加
                }
                path_val /= 10;
                node_stack.pop();
            }
        }
        return sum;
    }
};