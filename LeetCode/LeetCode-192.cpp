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
    vector<int> rightSideView(TreeNode* root) { // 层序遍历
        vector<int> res;

        std::queue<TreeNode*> node_stack;
        node_stack.push(root);

        while (!node_stack.empty()) {
            int ops = node_stack.size();
            for (int i = 0; i < ops; ++i) {
                TreeNode* node = node_stack.front();
                node_stack.pop();

                if (node == nullptr) break;
                if (node->left != nullptr) node_stack.push(node->left);
                if (node->right != nullptr) node_stack.push(node->right);
                if (i + 1 == ops) {
                    res.push_back(node->val);
                }
            }
        }
        return res;
    }
};