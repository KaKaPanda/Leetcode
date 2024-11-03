class Solution {
public:
    string intToRoman(int num) {
        string resp;
        string roman1 = "IXCM", roman5 = "VLD";

        if (num < 1 || num > 3999) return resp;

        int bit_count = 4;
        while (num > 0) {
            int divided = num / pow(10, bit_count - 1);
            if (divided == 0) {
                ; // do nothing
            }
            else if (divided >= 1 && divided < 4) {
                resp = resp + string(divided, roman1[bit_count-1]);
            }
            else if (divided == 4) {
                resp = resp + roman1[bit_count-1] + roman5[bit_count-1];  // 这里不要用+=
            }
            else if (divided >= 5 && divided < 9) {
                resp = resp + roman5[bit_count-1] + string(divided-5, roman1[bit_count-1]);
            }
            else if (divided == 9) {
                resp = resp + roman1[bit_count-1] + roman1[bit_count];
            }
            num -= divided * pow(10, bit_count - 1);
            --bit_count;
        }
        return resp;
    }
};