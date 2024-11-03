/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        std::unordered_map<Node*, Node*> cover_node_map, cur_node_map, nex_node_map; // 利用map来存储映射关系
        Node* new_node = new Node(node->val);
        cover_node_map[node] = new_node;
        cur_node_map[node] = new_node;

        while (!cur_node_map.empty()) {
            for (auto & cur_pair : cur_node_map) {
                for (auto & neighbor : cur_pair.first->neighbors) {
                    if (neighbor == nullptr) continue; // 跳过空指针
                    auto found_neighbor = cover_node_map.find(neighbor);
                    if (found_neighbor == cover_node_map.end()) { // 找不到节点则进行创建
                        Node* clone_node = new Node(neighbor->val);
                        cover_node_map[neighbor] = clone_node;
                        nex_node_map[neighbor] = clone_node;
                        found_neighbor = cover_node_map.find(neighbor); // 重新赋值
                    } 
                    cur_pair.second->neighbors.push_back(found_neighbor->second);
                }
            }

            cur_node_map = nex_node_map;
            nex_node_map.clear();
        }
        return new_node;
    }
};