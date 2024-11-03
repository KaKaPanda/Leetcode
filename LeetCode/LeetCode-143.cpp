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
    // 1 -> 2 -> 3 -> 4
    // 1 <- 2 <- 3  null
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *node1 = nullptr, *node2 = head;
        while (node2 != nullptr) {
            ListNode *temp = node2->next;
            node2->next = node1;
            node1 = node2;
            node2 = temp;
        }
        return node1;
    }

    ListNode* combineList(ListNode* head1, ListNode* head2) {
        if (head1 == nullptr) return head2;
        if (head2 == nullptr) return head1;

        ListNode* dummyHead = new ListNode(0, nullptr);
        ListNode* node = dummyHead;
        while (head1 != nullptr || head2 != nullptr) {
            if (head1 != nullptr) {
                node->next = head1;
                head1 = head1->next;
                node = node->next; // 这个不能提取到外面
            }
            if (head2 != nullptr) {
                node->next = head2;
                head2 = head2->next;
                node = node->next;
            }
        }
        return dummyHead->next;
    }

public:
    void reorderList(ListNode* head) { // 寻找链表中点 + 链表逆序 + 合并链表
        if (head == nullptr || head->next == nullptr) return;
        
        ListNode *p0 = nullptr, *p1 = head, *p2 = head;
        while (p2->next != nullptr) {
            if (p1->next != nullptr) {
                p0 = p1;
                p1 = p1->next;
            }
            if (p2->next != nullptr) p2 = p2->next;
            if (p2->next != nullptr) p2 = p2->next;
        }

        p0->next = nullptr; // 注意这里要断开连接
        p1 = reverseList(p1);
        head = combineList(head, p1);
        return;
    }
};