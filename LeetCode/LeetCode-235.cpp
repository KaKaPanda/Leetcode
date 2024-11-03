/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* commonAncestorPtr = root;
        if (!root || !p || !q) return nullptr;

        int small = min(p->val, q->val);
        int large = max(p->val, q->val);

        while (commonAncestorPtr != nullptr && commonAncestorPtr->val != small &&
            commonAncestorPtr->val != large) {
            if (small < commonAncestorPtr->val && large < commonAncestorPtr->val) {
                commonAncestorPtr = commonAncestorPtr->left;
            } else if (small > commonAncestorPtr->val && large > commonAncestorPtr->val) {
                commonAncestorPtr = commonAncestorPtr->right;
            } else {
                break;
            }
        }
        return commonAncestorPtr;
    }
};