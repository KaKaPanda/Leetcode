class Trie { // 字典树/前缀树
public:
    Trie(): isEnd(false) {}
    ~Trie() { // 需要析构函数释放资源
        for (auto & child : children) {
            if (child.second != nullptr) delete child.second;
        }
    }

    void Insert(const string& word) {
        Trie* node = this;
        for (auto ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    void Erase(const string& word) {
        Trie* node = this;
        std::unordered_map<Trie*, std::pair<Trie*, char>> node_reverse_map; // 反向字典进行剪枝
        for (auto ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return;
            }
            node_reverse_map[node->children[ch]] = {node, ch};
            node = node->children[ch];
        }
        
        node->isEnd = false;
        while (node->children.empty()) {
            auto pair = node_reverse_map[node];
            node = pair.first;
            node->children[pair.second] = nullptr; // 设置为空指针
        }
    }

    bool Empty() {
        for (auto & iter : this->children) {
            if (iter.second != nullptr) return false;
        }
        return true;
    }

    std::unordered_map<char, Trie*> children;
    bool isEnd;
};


class Solution { 
private:
    bool finish;
    int size_n, size_m;
    Trie* dictionary;
    vector<string> match_words;

    void dfs(vector<vector<char>>& board, const int& row, const int& col, const Trie* node, const string& word) {
        if (node == nullptr) return;
        if (node->isEnd) {
            match_words.emplace_back(word);
            dictionary->Erase(word); // 删除单词，避免重复添加
            finish = dictionary->Empty();
        }

        for (auto & iter : node->children) {
            if (iter.second == nullptr) continue;
            char ch = iter.first;
        
            if (!finish && col > 0 && board[row][col-1] == ch) { // 向左
                board[row][col-1] = 0; // 标记
                dfs(board, row, col-1, iter.second, word+ch);
                board[row][col-1] = ch; // 消除标记
            }
            if (!finish && col < size_m-1 && board[row][col+1] == ch) { // 向右
                board[row][col+1] = 0; // 标记
                dfs(board, row, col+1, iter.second, word+ch);
                board[row][col+1] = ch; // 消除标记
            }
            if (!finish && row > 0 && board[row-1][col] == ch) { // 向上
                board[row-1][col] = 0; // 标记
                dfs(board, row-1, col, iter.second, word+ch);
                board[row-1][col] = ch; // 消除标记
            }
            if (!finish && row < size_n-1 && board[row+1][col] == ch) { // 向下
                board[row+1][col] = 0; // 标记
                dfs(board, row+1, col, iter.second, word+ch);
                board[row+1][col] = ch; // 消除标记
            }
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        size_n = board.size();
        if (size_n == 0) return match_words;
        size_m = board[0].size();
        if (size_m == 0) return match_words;

        dictionary = new Trie();
        for (auto & word : words) {
            if (word.empty()) continue;
            dictionary->Insert(word);
        }

        for (int i = 0; i < size_n; ++i) {
            for (int j = 0; j < size_m; ++j) {
                for (auto & child : dictionary->children) {
                    if (board[i][j] != child.first) continue;
                    board[i][j] = 0;
                    dfs(board, i, j, child.second, string("") + child.first);
                    board[i][j] = child.first;
                }
                if (finish) break; // 前缀树为空退出循环
            }
            if (finish) break; // 前缀树为空退出循环
        }
        return match_words;
    }
};