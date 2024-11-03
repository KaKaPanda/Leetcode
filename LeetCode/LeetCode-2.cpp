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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode();
        ListNode* preNode = dummyHead;
        int flag = 0; // 注意处理好进位
        while(l1 != nullptr || l2 != nullptr || flag == 1) {
            ListNode* curNode = new ListNode();
            preNode->next = curNode;
            if (l1 != nullptr) {
                curNode->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                curNode->val += l2->val;
                l2 = l2->next;
            }

            curNode->val += flag;
            if (curNode->val >= 10) {
                curNode->val -= 10;
                flag = 1;
            } else {
                flag = 0;
            }
            preNode = preNode->next;
        }
        return dummyHead->next;
    }
};