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
    void searchPathSum(TreeNode* root, int targetSum, deque<int>& path) {
        if (root == nullptr) return;

        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == targetSum) {
                path.push_back(root->val);
                paths.emplace_back(vector<int>(path.begin(), path.end()));
                path.pop_back();
            }
            return;
        }

        path.push_back(root->val);
        if (root->left != nullptr) {
            searchPathSum(root->left, targetSum - root->val, path);
        }
        if (root->right != nullptr) {
            searchPathSum(root->right, targetSum - root->val, path);
        }
        path.pop_back();
        return;
    }


    vector<vector<int>> paths;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::deque<int> path;
        searchPathSum(root, targetSum, path);
        return paths;
    }
};