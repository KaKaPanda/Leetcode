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
    ListNode* cutList(ListNode* head, int cut) {
        if (head == nullptr || cut <= 0) return head;

        ListNode* tail = head;
        for (int count = 1; count < cut && tail != nullptr; ++count) {
            tail = tail->next;
        }

        if (tail == nullptr) return nullptr;

        ListNode* next_head = tail->next;
        tail->next = nullptr;
        return next_head;
    }

private:
    ListNode* mergeSortList(ListNode* pre_tail, ListNode* l1, ListNode* l2) {
        ListNode* node = pre_tail;
        while (l1 != nullptr || l2 != nullptr) {
            if (l2 == nullptr) {
                node->next = l1;
                l1 = l1->next;
            } else if (l1 == nullptr) {
                node->next = l2;
                l2 = l2->next;
            } else if (l1->val <= l2->val){
                node->next = l1;
                l1 = l1->next;
            } else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        return node;
    }
public:
    ListNode* sortList(ListNode* head) { // 归并排序，要求 O(nlogn)时间复杂度 和 常数级空间复杂度
        int node_num = 0;
        ListNode* node = head;
        while (node != nullptr) {
            ++node_num;
            node = node->next;
        }

        ListNode* dummyHead = new ListNode(0, head);
        for (int cut = 1; cut < node_num; cut <<= 1) {
            ListNode* pre_tail = dummyHead;
            ListNode* cur_head = pre_tail->next;
            
            while (cur_head != nullptr) {
                ListNode* nex_head = cutList(cur_head, cut);
                ListNode* thr_head = cutList(nex_head, cut);
                
                pre_tail = mergeSortList(pre_tail, cur_head, nex_head);
                cur_head = thr_head;
            }
        }
        return dummyHead->next;
    }
};