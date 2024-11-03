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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<int> level_res;
        vector<vector<int>> res;
        std::queue<TreeNode*> node_queue;
        node_queue.push(root);

        int level_node_num = 1;
        while (!node_queue.empty()) {
            TreeNode* node = node_queue.front();
            node_queue.pop();
            if (node == nullptr) {
                return res;
            }

            level_res.push_back(node->val);
            if (node->left) node_queue.push(node->left);
            if (node->right) node_queue.push(node->right);

            if (--level_node_num == 0) {
                level_node_num = node_queue.size();
                res.push_back(level_res);
                level_res.clear();
            }
        }

        std::reverse(res.begin(), res.end());
        
        return res;
    }
};