class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) return false;

        std::unordered_set<int> num_set;
        while (num_set.find(n) == num_set.end()) {
            num_set.insert(n);
            
            int next = 0;
            while (n) {
                int mod = n % 10;
                n /= 10;
                next += mod * mod;
            }

            if (next == 1) return true;
            n = next;
        }
        return false;
    }
};