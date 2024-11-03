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
    int countRightLevel(TreeNode* node, int cur_level) {
        while (node != nullptr) {
            ++cur_level;
            node = node->right;
        }
        return cur_level;
    }
public:
    int countNodes(TreeNode* root) { // 二分法搜索
        int total_node_num = 0;

        int right_level_num = 0;
        TreeNode *node = root;
        while (node != nullptr) {
            total_node_num += pow(2, right_level_num);
            ++right_level_num;
            node = node->right;
        }

        int cur_level_num = 0;
        int last_level_num = pow(2, right_level_num);
        TreeNode* cur_node = root;

        while (cur_node != nullptr) {
            int left_level_num = countRightLevel(cur_node->left, cur_level_num+1);
            if (left_level_num > right_level_num) {
                total_node_num += last_level_num / 2;
                cur_node = cur_node->right;
            } else {
                cur_node = cur_node->left;
            }
            last_level_num /= 2;
            cur_level_num++;
        }

        return total_node_num;
    }
};