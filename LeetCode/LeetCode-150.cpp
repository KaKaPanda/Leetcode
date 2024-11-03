class Solution {
public:
    // 逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。

    // 平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
    // 该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。
    // 逆波兰表达式主要有以下两个优点：

    // 1. 去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
    // 2. 适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中
    
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        std::stack<int> num_stk;

        for (int i = 0; i < tokens.size(); ++i) {
            if (!isOperation(tokens[i])) {
                num_stk.push(string2num(tokens[i]));
            } else {
                if (num_stk.empty()) return 0;
                int num2 = num_stk.top(); // 先拿到的是 num2
                num_stk.pop();
                if (num_stk.empty()) return 0;
                int num1 = num_stk.top();
                num_stk.pop();

                int ans = doOperation(tokens[i], num1, num2);
                num_stk.push(ans); // 要将计算结果压入栈
            }
        }
        return num_stk.empty() ? 0 : num_stk.top();
    }

private:
    bool isOperation(string token) {
        return (token == "+" || token == "-" || token == "*" || token == "/");
    }

    int doOperation(string token, int a, int b) {
        if (token == "+") return a + b;
        if (token == "-") return a - b;
        if (token == "*") return a * b;
        if (token == "/") return a / b;
        return 0;
    }

    int string2num(string token) {
        int res = 0, sign = 1;
        for (int i = 0; i < token.size(); ++i) {
            if (i == 0 && token[i] == '-') { // 捕获负号
                sign = -1;
                continue;
            }
            res = res * 10 + (token[i] - '0');
        }
        return res * sign;
    }
};