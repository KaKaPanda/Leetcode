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
    struct Compare { // 函数对象
        bool operator() (const ListNode* a, const ListNode* b) const {
            if (a != nullptr && b!= nullptr) {
                return a->val > b->val; // 最小堆
            } else {
                return false;
            }
        }
    }; // 注意要加分号

    ListNode* mergeKLists(vector<ListNode*>& lists) {  // 普通方法遍历时间复杂度高，需要使用优先队列
        
        priority_queue<ListNode*, std::vector<ListNode*>, Compare> pq;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }
        
        ListNode* dummyHead = new ListNode();
        ListNode* dummyNode = dummyHead;
        
        while (!pq.empty()) {
            ListNode* min_node = pq.top();
            pq.pop();

            dummyNode->next = min_node;
            dummyNode = dummyNode->next;

            if (min_node->next != nullptr) {
                pq.push(min_node->next);
            }
        }
        return dummyHead->next;
    }
};