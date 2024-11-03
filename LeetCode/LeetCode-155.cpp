class MinStack {
private:
    std::stack<int> num_stack; 
    std::stack<int> min_stack;

public:
    MinStack() {}
    
    void push(int val) {
        num_stack.push(val);
        if (min_stack.empty() || min_stack.top() >= val) {
            min_stack.push(val);
        }
    }
    
    void pop() {
        if (num_stack.top() == min_stack.top()) {
            min_stack.pop();
        }
        num_stack.pop();
    }
    
    int top() {
        if (num_stack.empty()) return INT_MIN;
        return num_stack.top();
    }
    
    int getMin() {
        if (min_stack.empty()) return INT_MIN;
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */