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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* dummyNode = dummyHead;

        if (k == 1) {
            return dummyHead->next; // k=1直接返回
        }

        while (true) {
            int count = k;
            vector<ListNode*> node_vec;
            ListNode* groupNode = dummyNode;

            while (count-- && groupNode->next != nullptr) {
                node_vec.push_back(groupNode->next);
                groupNode = groupNode->next;
            }
            
            if (node_vec.size() < k) {
                break; // 元素数量少于k跳出循环
            } else {
                ListNode* groupNext = groupNode->next;
                groupNode = dummyNode;
                for (int i = node_vec.size()-1; i >= 0; --i) {
                    groupNode->next = node_vec[i];
                    groupNode = groupNode->next;
                }
                groupNode->next = groupNext;
                dummyNode = groupNode; // 最后要更新 dummyNode
            }
        }

        return dummyHead->next;
    }
};