/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode *p1 = headA, *p2 = headB;
        while (p1 != p2) {
            p1 = (p1 == nullptr)? headB : p1->next; // 需要让指针步进到 nullptr, 这是不相交链表结束的条件
            p2 = (p2 == nullptr)? headA : p2->next;
        }
        return p1;
    }
};