class Solution {
public:
    bool isPalindrome(string s) {
        int p1 = 0, p2 = s.size()-1;

        while (p1 <= p2) {
            while (p1 < s.size() && !isalnum(s[p1])) {
                ++p1;
            }
            while (p2 >= 0 && !isalnum(s[p2])) {
                --p2;
            }
            if (p1 >= s.size() || p2 < 0) break;

            if (tolower(s[p1]) != tolower(s[p2])) {
                return false;
            } else {
                ++p1;
                --p2;
            }
        }
        return true;
    }
};