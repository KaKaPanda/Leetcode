class Trie {
private:
    vector<Trie*> children; // 每个节点可以根据26个字母进行分叉
    bool isEnd;             // 表示单词结尾

Trie* searchNode(const string& word) {
    Trie* node = this;      // 根节点为 this 
    for (auto & c : word) {
        int idx = c - 'a';
        if (idx < 0 || idx >= 26) return nullptr;

        if (node->children[idx] == nullptr) {
            return nullptr;
        }
        node = node->children[idx];
    }
    return node;
}

public:
    Trie() : children(26), isEnd(false) { } // 初始化为false
    ~Trie() { // 需要析构函数释放资源
        for (auto & child : children) {
            if (child != nullptr) {
                delete child;
            }
        }
    }
    
    void insert(string word) {
        Trie* node = this;
        for (auto & c : word) {
            int idx = c - 'a';
            if (idx < 0 || idx >= 26) return;
            if (node->children[idx] == nullptr) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = searchNode(word);
        return (node != nullptr && node->isEnd);
    }
    
    bool startsWith(string prefix) {
        Trie* node = searchNode(prefix);
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */