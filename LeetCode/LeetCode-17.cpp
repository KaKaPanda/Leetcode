class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::unordered_map<char, vector<string>> key_digits_map;
        key_digits_map.insert({'2', {"a", "b", "c"}});
        key_digits_map.insert({'3', {"d", "e", "f"}});
        key_digits_map.insert({'4', {"g", "h", "i"}});
        key_digits_map.insert({'5', {"j", "k", "l"}});
        key_digits_map.insert({'6', {"m", "n", "o"}});
        key_digits_map.insert({'7', {"p", "q", "r", "s"}});
        key_digits_map.insert({'8', {"t", "u", "v"}});
        key_digits_map.insert({'9', {"w", "x", "y", "z"}});

        vector<string> res;
        if (digits.size() > 0) {
            res = key_digits_map.at(digits[0]);
        }

        for (int i = 1; i < digits.size(); i++) {
            int loop_res_size = res.size();
            auto found = key_digits_map.find(digits[i]);
            if (found == key_digits_map.end()) {
                continue;
            }
            auto found_dights = found->second;

            for (int j = 0; j < found_dights.size(); ++j) {
                for (int k = 0; k < loop_res_size; ++k) {
                    if (j == 0) { // 第一个字符直接插入
                        res[k] += found_dights[j];
                    } else { // 后续字符需要拷贝替换
                        string copy_str = res[k];
                        copy_str[copy_str.size()-1] = found_dights[j][0];
                        res.push_back( copy_str );
                    }
                }
            }
        }
        return res;
    }
};