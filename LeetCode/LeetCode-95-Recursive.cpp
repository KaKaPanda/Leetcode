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
    vector<TreeNode*> generateSubTrees(int n1, int n2) {
        vector<TreeNode*> res;
        if (n1 > n2) {
            res.push_back(nullptr);
            return res;
        }
        if (n1 == n2) {
            res.push_back(new TreeNode(n1));
            return res;
        }

        for (int i = n1; i <= n2; ++i) {
            vector<TreeNode*> left_tree = generateSubTrees(n1, i-1);
            vector<TreeNode*> right_tree = generateSubTrees(i+1, n2);

            for (int j = 0; j < left_tree.size(); ++j) {
                for (int k = 0; k < right_tree.size(); ++k) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_tree[j];
                    root->right = right_tree[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generateSubTrees(1, n);
    }
};