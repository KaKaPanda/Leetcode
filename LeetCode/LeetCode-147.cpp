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
private:
    ListNode* insertNode(ListNode* head, ListNode* insert_node) {
        if (head == nullptr) return insert_node;
        if (insert_node == nullptr) return head;
        if (insert_node->val < head->val) {
            insert_node->next = head;
            head = insert_node;
            return head;
        }

        ListNode *pre_node = head, *cur_node = head->next;
        while (cur_node != nullptr && cur_node->val < insert_node->val) {
            pre_node = cur_node;
            cur_node = cur_node->next;
        }
        pre_node->next = insert_node;
        insert_node->next = cur_node;
        return head;
    }

public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* pre_node = head;
        ListNode* cur_node = head->next;
        ListNode* nex_node = nullptr;
        while (cur_node != nullptr) {
            nex_node = cur_node->next;
            if (pre_node->val > cur_node->val) {
                pre_node->next = nex_node;
                cur_node->next = nullptr;
                head = insertNode(head, cur_node);
            } else {
                pre_node = cur_node;
            }
            cur_node = nex_node;
        }
        return head;
    }
};