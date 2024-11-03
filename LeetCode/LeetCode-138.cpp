/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        std::unordered_map<Node*, Node*> cover_node_map, cur_node_map, nex_node_map;

        Node* new_head = new Node(head->val);
        cover_node_map[head] = new_head;
        cur_node_map[head] = new_head;

        while (!cur_node_map.empty()) {
            for (auto & cur_node : cur_node_map) {
                if (cur_node.first->next != nullptr) {
                    auto found_next = cover_node_map.find(cur_node.first->next);
                    if (found_next == cover_node_map.end()) {
                        Node* new_node = new Node(cur_node.first->next->val);
                        cover_node_map[cur_node.first->next] = new_node;
                        nex_node_map[cur_node.first->next] = new_node;
                        found_next = cover_node_map.find(cur_node.first->next);
                    }
                    cur_node.second->next = found_next->second;
                }

                if (cur_node.first->random != nullptr) {
                    auto found_random = cover_node_map.find(cur_node.first->random);
                    if (found_random == cover_node_map.end()) {
                        Node* new_node = new Node(cur_node.first->random->val);
                        cover_node_map[cur_node.first->random] = new_node;
                        nex_node_map[cur_node.first->random] = new_node;
                        found_random = cover_node_map.find(cur_node.first->random);
                    }
                    cur_node.second->random = found_random->second;
                }
            }
            cur_node_map = nex_node_map;
            nex_node_map.clear();
        }
        return new_head;
    }
};