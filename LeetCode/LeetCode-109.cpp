/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* subSortedListToBST(ListNode* head, int len) {
        if (len == 0) return nullptr;

        TreeNode* mid_node = new TreeNode();
        int right_len = len / 2;
        int left_len = len - right_len - 1;
        
        ListNode* cur_node = head;
        int step_count = 0;
        while (step_count++ != left_len) {
            cur_node = cur_node->next;
        }
        mid_node->val = cur_node->val;

        if (left_len > 0) {
            TreeNode* left_tree = subSortedListToBST(head, left_len);
            mid_node->left = left_tree;
        }
        if (right_len > 0) {
            TreeNode* right_tree = subSortedListToBST(cur_node->next, right_len);
            mid_node->right = right_tree;
        }
        return mid_node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int node_count = 0;
        ListNode* cur_node = head;
        while (cur_node != nullptr) {
            ++node_count;
            cur_node = cur_node->next;
        }

        return subSortedListToBST(head, node_count);
    }
};