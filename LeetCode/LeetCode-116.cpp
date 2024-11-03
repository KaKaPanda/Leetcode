/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;

        Node* cur_list_node = root;
        Node* nex_list_node = nullptr;
        Node* nex_list_head = nullptr;

        while (cur_list_node != nullptr) {
            if (cur_list_node->left != nullptr) { // 先检查左叶子
                if (nex_list_node != nullptr) {
                    nex_list_node->next = cur_list_node->left;
                }
                nex_list_node = cur_list_node->left;
                if (nex_list_head == nullptr) { // 是否更新下一层链表头
                    nex_list_head = nex_list_node;
                }
            }
            if (cur_list_node->right != nullptr) { // 再检查右叶子
                if (nex_list_node != nullptr) {
                    nex_list_node->next = cur_list_node->right;
                }
                nex_list_node = cur_list_node->right;
                if (nex_list_head == nullptr) { // 是否更新下一层链表头
                    nex_list_head = nex_list_node;
                }
            }
            cur_list_node = cur_list_node->next; 

            if (cur_list_node == nullptr && nex_list_head != nullptr) { // 更新到下一层链表
                cur_list_node = nex_list_head;
                nex_list_node = nullptr;  // 注意清空此变量
                nex_list_head = nullptr;
            }
        }
        return root;
    }
};