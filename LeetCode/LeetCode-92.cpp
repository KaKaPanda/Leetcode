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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left >= right) return head;

        ListNode* dummyHead = new ListNode(0, head);
        ListNode* preNode = dummyHead;
        ListNode* curNode = head;
        ListNode* nexNode = head->next;

        int reverseOps = right - left;

        while (--left && nexNode != nullptr) {  // 先找到需要反转的起始位置
            preNode = curNode;
            curNode = nexNode;
            nexNode = nexNode->next;
        }

        while (reverseOps-- && nexNode != nullptr) { // 将后续节点的指向进行反转
            ListNode* tmpNode = nexNode; // 需要注意这里交换操作
            nexNode = nexNode->next;
            tmpNode->next = curNode;
            curNode = tmpNode;
        }

        preNode->next->next = nexNode; // 最后再修改首尾指向
        preNode->next = curNode;

        return dummyHead->next;
    }
};