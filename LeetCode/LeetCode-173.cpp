/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> node_stack;
public:
    // next() 和 hasNext() 操作均摊时间复杂度为 O(1) ，并使用 O(h) 内存。其中 h 是树的高度。
    // 使用栈数据结构来遍历
    BSTIterator(TreeNode* root) {
        while (root != nullptr) {
            node_stack.push(root);
            root = root->left;
        }
    }
    
    int next() {
        if (node_stack.empty()) return INT_MIN;

        TreeNode* node = node_stack.top();
        node_stack.pop(); // 注意将当前节点弹出栈

        int nextV = node->val; // 中序遍历先拿父节点的值
        if (node->right != nullptr) {
            node = node->right;
            while (node != nullptr) { // node 向右走在将左链压入栈
                node_stack.push(node);
                node = node->left;
            }
        }
        return nextV;
    }
    
    bool hasNext() {
        return !node_stack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */