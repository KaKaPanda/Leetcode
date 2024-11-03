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
    bool hasCycle(ListNode *head) { // 哈希表 或者 快慢指针
        if (head == nullptr) return false;

        ListNode *p1 = head, *p2 = head;
        while (p1->next != nullptr || p2->next != nullptr) {
            if (p1->next != nullptr) p1 = p1->next;
            if (p2->next != nullptr) p2 = p2->next;
            if (p2->next != nullptr) {
                p2 = p2->next;
                if (p1 == p2) return true; // 在第二步里面判断
            }
        }
        return false;
    }
};