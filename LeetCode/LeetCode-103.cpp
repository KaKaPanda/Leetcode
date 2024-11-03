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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) { // [3,9,20,null,null,15,7]
        vector<int> level_res;
        vector<vector<int>> res;
        std::queue<TreeNode*> node_queue;
        node_queue.push(root);
        
        bool level_node_reverse = false;
        int level_node_num = 1;
        while (!node_queue.empty()) {

            TreeNode* node = node_queue.front();
            if (node != nullptr) {
                level_res.push_back(node->val);
            } else {
                return res; // 空指针直接返回
            }

            if (node->left) node_queue.push(node->left);
            if (node->right) node_queue.push(node->right);

            node_queue.pop();
            if (--level_node_num == 0) {
                if (level_node_reverse) {
                    std::reverse(level_res.begin(), level_res.end());
                }
                level_node_reverse = !level_node_reverse;
                
                res.push_back(level_res);
                level_res.clear();
                level_node_num = node_queue.size();
            }
        }
        return res;
    }
};