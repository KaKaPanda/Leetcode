class Solution {
public:
    bool isValid(string s) {

        stack<char> brackets_stack;  // 使用栈来解决
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
                brackets_stack.push(s[i]);
            } else if (brackets_stack.empty()) { // 先判断栈是否为空
                return false;
            } else if (((s[i] == ']' && brackets_stack.top() != '[')) ||
                       ((s[i] == '}' && brackets_stack.top() != '{')) ||
                       ((s[i] == ')' && brackets_stack.top() != '('))) {
                return false;
            } else {
                brackets_stack.pop();
            }
        }
        return brackets_stack.empty(); // 最后判断栈是否为空
    }
};