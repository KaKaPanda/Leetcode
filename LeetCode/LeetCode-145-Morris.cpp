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
private:
    void addPath(vector<int>& vec, TreeNode* node) { // 逆序添加节点右侧链表
        int count = 0;
        while (node != nullptr) {
            ++count;
            vec.push_back(node->val);
            node = node->right;
        }
        std::reverse(vec.end() - count, vec.end());
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
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
                    predecessor->right = node;
                    node = node->left;
                } else {
                    predecessor->right = nullptr;
                    addPath(res, node->left);
                    node = node->right;
                }
            } else {
                node = node->right;
            }
        }
        addPath(res, root); // 最后逆序添加根节点的右侧链表
        return res;
    }
};