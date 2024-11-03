class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<int> left_used_vec, right_used_vec;
        if (n == 0) {
            return result;
        }

        result.push_back("(");
        left_used_vec.push_back(1);
        right_used_vec.push_back(0);
        
        int loop = n;
        while (--loop) {
            int loop_result_size = result.size();
            for (int i = 0; i < loop_result_size; ++i) {
                // 循环加右括号 + 左括号
                int max_add_right = left_used_vec[i] - right_used_vec[i];
                for (int j = 1; j <= max_add_right; ++j) {
                    string temp = result[i] + (string(j, ')') + "(");
                    result.push_back(temp); // 不要直接 push_back 原容器的元素
                    left_used_vec.push_back(left_used_vec[i]+1);
                    right_used_vec.push_back(right_used_vec[i]+j);
                }
                // 最后在原来的位置直接加左括号
                result[i] += "(";
                left_used_vec[i] += 1;
            }
        }

        for (int k = 0; k < result.size(); ++k) {
            int max_add_right = left_used_vec[k] - right_used_vec[k];
            if (max_add_right > 0) {
                result[k] += string(max_add_right, ')');
            }
        }

        return result;
    }
};