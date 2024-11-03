class MyStack { // 进阶：你能否仅用一个队列来实现栈
    std::queue<int> queue_adapter;
public:
    MyStack() {}
    
    void push(int x) {
        int loop = queue_adapter.size();
        queue_adapter.push(x);
        for (int i = 0; i < loop; ++i) {
            queue_adapter.push(queue_adapter.front());
            queue_adapter.pop();
        }
    }
    
    int pop() {
        int val = queue_adapter.front();
        queue_adapter.pop();
        return val;
    }
    
    int top() {
        return queue_adapter.front();
    }
    
    bool empty() {
        return queue_adapter.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */