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
    // 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7] preorder 和 inorder 均 无重复 元素
    // 输出: [3,9,20,null,null,15,7]
    TreeNode* buildSubTree(const vector<int>& preorder, const vector<int>& inorder, int i, int j, int len) {
        TreeNode* head = new TreeNode(preorder[i]);
        if (len == 1) {
            return head;
        }

        int left_len = 0, right_len = 0;
        for (int k = j; k < j + len; ++k) {
            if (inorder[k] == preorder[i]) { // preorder 首元素为head, 在 inorder 里面划分左树和右树
                left_len = k - j;
                right_len = len - 1 - left_len;
                break;
            }
        }
        if (left_len > 0) {
            TreeNode* left_tree = buildSubTree(preorder, inorder, i+1, j, left_len);
            head->left = left_tree;
        }
        if (right_len > 0) {
            TreeNode* right_tree = buildSubTree(preorder, inorder, i+left_len+1, j+left_len+1, right_len);
            head->right = right_tree;
        }
        return head;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int cnt = preorder.size();
        if (preorder.size() != inorder.size() || cnt == 0) {
            return nullptr;
        }

        return buildSubTree(preorder, inorder, 0, 0, cnt);
    }
};
