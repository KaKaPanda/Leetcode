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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode();
        ListNode *node0, *node1, *node2, *node3;

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        node0 = dummyHead;
        node1 = head;
        node2 = node1->next;
        node3 = node2->next;
        while (true) {
            node0->next = node2;
            node2->next = node1;
            node1->next = node3;

            node0 = node1;
            node1 = node3;
            if (node3 == nullptr) break;
            node2 = node3->next;
            if (node2 == nullptr) break;
            node3 = node2->next;
        }
        return dummyHead->next;
    }
};