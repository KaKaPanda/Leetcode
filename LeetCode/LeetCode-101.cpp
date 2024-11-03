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
class Solution { // 层序遍历
public:
    bool isSymmetric(TreeNode* root) { 
        std::vector<TreeNode*> node_vec;
        node_vec.push_back(root);
        
        bool all_node_null = false;
        while (!all_node_null) {
            std::vector<TreeNode*> node_vec_new;
            for (int i = 0; i < node_vec.size(); ++i) {
                node_vec_new.push_back((node_vec[i] == nullptr) ? nullptr : node_vec[i]->left);
                node_vec_new.push_back((node_vec[i] == nullptr) ? nullptr : node_vec[i]->right);
            }

            all_node_null = true;
            for (int i = 0, j = node_vec_new.size()-1; i < j; ++i, --j) {
                if (node_vec_new[i] != nullptr || node_vec_new[j] != nullptr) {
                    all_node_null = false;
                }

                if (node_vec_new[i] == nullptr && node_vec_new[j] == nullptr) {
                    continue; // 都为空指针跳过
                }
                if (node_vec_new[i] != nullptr && node_vec_new[j] != nullptr) {
                    if (node_vec_new[i]->val == node_vec_new[j]->val) {
                        continue; // 都不为空指针且值相等跳过
                    }
                }
                return false;
            }

            node_vec = node_vec_new;
        }

        return true;
    }
};

class Solution { // 递归调用，效率更好
public:
    bool subSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;

        if (left != nullptr && right != nullptr) {
            if (left->val != right->val) {
                return false;
            } else {
                return subSymmetric(left->left, right->right) && subSymmetric(left->right, right->left);
            }
        } else {
            return false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return subSymmetric(root->left, root->right);
    }
};