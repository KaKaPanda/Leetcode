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
    ListNode* rotateRight(ListNode* head, int k) { // 注意是向右滚动
        if (head == nullptr) return head;

        // 累计有多少个节点, 同时找出尾节点
        int count = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            count++;
            tail = tail->next;
        }

        // 特殊数值直接返回
        k = count - (k % count); // 转换为向左滚动
        if (count == 1 || k == 0) return head;

        ListNode* node = head;
        
        while (--k) {
            node = node->next;
        }

        tail->next = head;
        head = node->next;
        node->next = nullptr;
        return head;
    }
};