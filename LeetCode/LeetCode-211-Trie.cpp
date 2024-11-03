class WordDictionary {
private:
    std::vector<WordDictionary*> children;
    bool isEnd;

    bool dfs(WordDictionary* node, const string& word, const int cur) {
        if (node == nullptr) return false;
        if (word.size() == cur) return node->isEnd;

        if (word[cur] == '.') {
            bool found = false;
            for (auto & child : node->children) {
                if (child == nullptr) continue;
                found |= dfs(child, word, cur + 1);
                if (found) break;
            }
            return found;
        } else {
            int idx = word[cur] - 'a';
            if (idx < 0 || idx >= 26) return false;
            return dfs(node->children[idx], word, cur + 1);
        }
        return false;
    }

public:
    WordDictionary() : children(26), isEnd(false) {}
    ~WordDictionary() { // 需要析构函数释放资源
        for (auto & child : children) {
            if (child != nullptr) {
                delete child;
            }
        }
    }
    
    void addWord(string word) {
        WordDictionary* node = this;
        for (auto & ch : word) {
            int idx = ch - 'a';
            if (idx < 0 || idx >= 26) return;

            if (node->children[idx] == nullptr) {
                node->children[idx] = new WordDictionary();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(this, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */