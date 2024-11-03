class Solution {
public:
    // 门电路设计, 按位进行转换
    // twice once           低位与num运算后的值为: o ^ n, 10+1 需要同 ~t 进行与运算转换到 00 
    // 0     0    + 0/1     o_ = ~t & (o ^ n)
    // 0     1    + 0/1     t_ = ~t & (o ^ n) ^ (t ^ n) = o_ ^ (t ^ n) // 该公式为题解公司，但是看不出含义
    // 1     0    + 0/1     t_ = t ^ ((t | o) & n)  // 该公式为推理公式，((t | o) & n) 表明 t 需要变化，则与 t 再进行异或

    int singleNumber(vector<int>& nums) {
        int seen_once = 0, seen_twice = 0;
        for (auto &num : nums) {
            int last_once = seen_once;
            seen_once = (~seen_twice) & (last_once ^ num);
            seen_twice = seen_twice ^ ((seen_twice | last_once) & num);
        }
        return seen_once;
    }
};