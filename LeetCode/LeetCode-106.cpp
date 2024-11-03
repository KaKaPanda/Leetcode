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
    TreeNode* buildSubTree(const vector<int>& inorder, const vector<int>& postorder, int i, int j, int len) {
        TreeNode* head = new TreeNode(postorder[j]);
        
        int left_len = 0, right_len = 0;
        for (int k = i; k < i + len; ++k) {
            if (inorder[k] == postorder[j]) {
                left_len = k - i;
                right_len = len - 1 - left_len;
                break;
            }
        }
        if (left_len > 0) {
            TreeNode* left_tree = buildSubTree(inorder, postorder, i, j - right_len - 1, left_len);
            head->left = left_tree;
        }
        if (right_len > 0) {
            TreeNode* right_tree = buildSubTree(inorder, postorder, i + left_len + 1, j - 1, right_len);
            head->right = right_tree;
        }
        return head;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int cnt = inorder.size();
        if (inorder.size() != postorder.size() || cnt == 0) return nullptr;

        return buildSubTree(inorder, postorder, 0, cnt - 1, cnt);
    }
};