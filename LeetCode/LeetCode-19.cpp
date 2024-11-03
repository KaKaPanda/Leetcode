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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (n <= 0) return head;

        ListNode* dummyHead = new ListNode(0, head);
        ListNode* node1 = dummyHead;
        ListNode* node2 = head;
        while(n-- && node2 != nullptr) {  // 创建双指针，后面的指针先走n步
            node2 = node2->next;
        }

        while(node2 != nullptr) {
            node1 = node1->next;
            node2 = node2->next;
        }

        node1->next = node1->next->next; // 删除指定位置元素
        return dummyHead->next;
    }
};