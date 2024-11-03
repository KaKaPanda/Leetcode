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
    bool isValidBST(TreeNode* root) {
        long long val = (long long)INT_MIN - 1;
        stack<TreeNode*> stk;

        while(root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left; // 优先遍历左树
            }

            root = stk.top();
            stk.pop();
            if (root->val > val) {
                val = root->val; // 检查值是否单调
            } else {
                return false;
            }
            
            root = root->right; // 无论如何都要往右走
        }
        return true;
    }
};