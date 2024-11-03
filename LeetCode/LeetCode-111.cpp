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
    int minDepth(TreeNode* root) {
        int min_depth = 0;
        if (root == nullptr) return min_depth;

        std::queue<TreeNode*> node_queue;
        node_queue.push(root);
        ++min_depth;

        int level_node_num = 1;
        while (!node_queue.empty()) {
            TreeNode* node = node_queue.front();
            node_queue.pop();

            if (node->left == nullptr && node->right == nullptr) break;
            if (node->left) node_queue.push(node->left);
            if (node->right) node_queue.push(node->right);
            
            if (--level_node_num == 0) {
                level_node_num = node_queue.size();
                ++min_depth;
            }
        }
        return min_depth;
    }
};