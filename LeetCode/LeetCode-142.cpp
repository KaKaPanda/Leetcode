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
    ListNode *detectCycle(ListNode *head) { // 哈希表 或者 快慢指针
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode *p1 = head, *p2 = head;
        while (p1->next != nullptr || p2->next != nullptr) {
            if (p1->next != nullptr) p1 = p1->next;
            if (p2->next != nullptr) p2 = p2->next;
            if (p2->next != nullptr) {
                p2 = p2->next;

                if (p1 == p2) {
                    p2 = head;
                    while (p1 != p2) {
                        p1 = p1->next;
                        p2 = p2->next;
                    }
                    return p1;
                };
            }
        }

        return nullptr;
    }
};
