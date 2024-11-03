class Solution {
public:
    // 请注意，返回的 规范路径 必须遵循下述格式：
    // 始终以斜杠 '/' 开头。
    // 两个目录名之间必须只有一个斜杠 '/' 。
    // 最后一个目录名（如果存在）不能 以 '/' 结尾。
    // 此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
    // 返回简化后得到的 规范路径 。

    // 1 <= path.length <= 3000
    // path 由英文字母，数字，'.'，'/' 或 '_' 组成。
    // path 是一个有效的 Unix 风格绝对路径

    vector<string> split(const string& path, const char& delim) { // 先将路径进行分割
        vector<string> res;
        for (int i = 0, step = 1; i < path.size(); i += step) {
            step = 1; // 注意这里需要重新初始化
            if (path[i] == delim) continue; 
            while (i+step < path.size() && path[i+step] != '/') {
                ++step;
            }
            res.push_back(path.substr(i, step));
        }
        return res;
    }

    string simplifyPath(string path) { // "/.../a/../b/c/../d/./"
        stack<string> stk;
        vector<string> paths = split(path, '/');

        for (int i = 0; i < paths.size(); ++i) {
            if (paths[i] == ".") { // 忽略路径
                continue;
            } else if (paths[i] == "..") {
                if (!stk.empty()) stk.pop(); // 弹出路径
            } else {
                stk.push(paths[i]); // 压入路径
            }
        }

        // 倒出栈
        string res;
        if (stk.empty()) {
            return "/";
        } else {
            while (!stk.empty()) {
                string sub_path = stk.top();
                stk.pop();
                res = '/' + sub_path + res;
            }
        }
        return res;
    }
};