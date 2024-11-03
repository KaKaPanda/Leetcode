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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* dummyHead = new ListNode(0, head);
        ListNode* pre_node = dummyHead;
        ListNode* cur_node = head;

        while (cur_node != nullptr && cur_node->next != nullptr) { // 内部的 while 循环可能会导致 cur_node 为空, 需要加一层判断
            if (cur_node->val != cur_node->next->val) {
                pre_node = cur_node; // pre_node 也要步进
                cur_node = cur_node->next;
                continue;
            }

            while (cur_node->next != nullptr && cur_node->val == cur_node->next->val) {
                cur_node->next = cur_node->next->next; // 删除后续重复节点
            }
            pre_node->next = cur_node->next; // 删除当前重复节点
            cur_node = cur_node->next;
        }
        return dummyHead->next;
    }
};