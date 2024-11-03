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
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        std::queue<TreeNode*> node_queue;
        node_queue.push(root);

        int level_node_num = 1;
        while (!node_queue.empty()) {
            TreeNode* node = node_queue.front();
            node_queue.pop();
            if (node == nullptr) {
                return max_depth;
            }

            if (node->left) node_queue.push(node->left);
            if (node->right) node_queue.push(node->right);

            if (--level_node_num == 0) {
                ++max_depth;
                level_node_num = node_queue.size();
            }
        }
        return max_depth;
    }
};