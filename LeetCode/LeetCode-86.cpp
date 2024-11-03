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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* pre_node = dummyHead;
        ListNode* cur_node = dummyHead;

        bool has_cross_larger_num = false;
        while (cur_node->next != nullptr) { // 这里需要交换链表中两处节点，最好利用下一个节点的值来判断
            if (cur_node->next->val >= x) {
                has_cross_larger_num = true;
                cur_node = cur_node->next; // 大数直接移动当前节点
            } 
            else if (cur_node->next->val < x) {
                if (!has_cross_larger_num) { // 没有遇到过大数，直接移动当前节点和前置节点
                    pre_node = cur_node->next;
                    cur_node = cur_node->next;
                    continue;
                }
                ListNode* temp = pre_node->next;
                pre_node->next = cur_node->next;
                cur_node->next = cur_node->next->next; // 后半段链表也要衔接上
                // cur_node = cur_node->next; 这句是错误的, 链接后不能再步进了
                pre_node = pre_node->next;
                pre_node->next = temp;
            }
        }
        return dummyHead->next;
    }
};