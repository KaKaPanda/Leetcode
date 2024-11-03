struct LRUItem {
    int key;
    int val;
    LRUItem* prev;
    LRUItem* next;

    LRUItem(): key(0), val(0), prev(nullptr), next(nullptr) {}
    LRUItem(int key_, int val_): key(key_), val(val_), prev(nullptr), next(nullptr) {}
};

class LRUCache { // 哈希表+双链表
private:
    int capacity;
    std::unordered_map<int, LRUItem*> item_map;
    LRUItem* head;
    LRUItem* tail;

    void moveToHead(LRUItem* item) { // 需要修改多个指针
        if (item->prev != head) {
            item->prev->next = item->next;
            item->next->prev = item->prev;
            head->next->prev = item;
            item->next = head->next;
            head->next = item;
            item->prev = head;
        }
    }

    void removeTail() {
        auto remove_item = tail->prev;
        remove_item->prev->next = tail;
        tail->prev = remove_item->prev;
        remove_item->prev = nullptr;
        remove_item->next = nullptr;
        item_map.erase(remove_item->key); // 哈希表按 key 删除元素
        delete remove_item; // 删除指针
    }

public:
    LRUCache(int capacity_): capacity(capacity_) {
        head = new LRUItem();
        tail = new LRUItem();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        auto iter = item_map.find(key);
        if (iter == item_map.end()) {
            return -1;
        }

        auto item = iter->second;
        moveToHead(item); // 需要移动到链表头
        return item->val;
    }
    
    void put(int key, int value) {
        auto iter = item_map.find(key);
        if (iter != item_map.end()) { // 元素存在，需要移动到头节点
            auto item = iter->second;
            item->val = value; // 需要更新值
            moveToHead(item);
            return;
        }

        if (iter == item_map.end()) { // 不存在元素需要插入
            auto item = new LRUItem(key, value);
            item_map[key] = item; // 哈希表按 key 插入元素
            head->next->prev = item;
            item->next = head->next;
            head->next = item;
            item->prev = head;
        }

        if (item_map.size() > capacity) {
            removeTail();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */