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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode();
        ListNode* curNode = dummyHead;

        while (list1 != nullptr || list2 != nullptr) {
            if (list1 == nullptr) {
                curNode->next = list2;
                break;
            } else if (list2 == nullptr) {
                curNode->next = list1;
                break;
            } else if (list1->val < list2->val) {
                curNode->next = list1;
                curNode = curNode->next; // 移动新链表节点
                list1 = list1->next;     // 移动原链表节点
            } else {
                curNode->next = list2;
                curNode = curNode->next;
                list2 = list2->next;
            }
        }

        return dummyHead->next;
    }
};