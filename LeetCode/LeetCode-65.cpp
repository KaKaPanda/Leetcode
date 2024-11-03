class Solution {
public:
    // start -> [sign, number]
    // number -> [number, tech, end] point算在number里面,一个number只能带一个point
    // sign -> [number]
    // tech -> [number, sign+number] 其中number不能包含point

    int tech_count = 0;
    int point_count = 0;

    string getNextState(const char& c) {
        if (c >= '0' && c <= '9' || c == '.') {
            if (c == '.') {
                if (tech_count == 1) return "none"; // 科学记数法后面只能带整数
                ++point_count;
            }
            if (point_count > 1) return "none"; // number里面只能有一个point
            return "number";
        } else if (c == '+' || c == '-') {
            return "sign";
        } else if (c == 'e' || c == 'E') {
            if (tech_count == 0) point_count = 0;
            if (++tech_count > 1) return "none"; // 一个有效数字里面只能有一个e
            return "tech";
        } else {
            return "none";
        }
    }
    
    bool isNumber(string s) {
        std::unordered_map<string, set<string>> state_machine;
        state_machine["start"] = set<string>{"sign", "number"};
        state_machine["number"] = set<string>{"number", "tech", "end"};
        state_machine["sign"] = set<string>{"number"};
        state_machine["tech"] = set<string>{"number"}; // 需要自行跳过后面的sign

        string state = "start";

        for (int i = 0; i < s.size(); ++i) {
            auto tranState = state_machine[state];
            string nextState = getNextState(s[i]);

            if (s[i] == '.' && state != "number") { // 小数点前面没有数字特殊判断
                if (!(i+1 < s.size() && s[i+1] >= '0' && s[i+1] <= '9')) {
                    return false;
                }
            }

            if (state == "tech" && nextState == "sign") {
                continue; // 跳过科学记数法后面的符号
            }

            if (tranState.find(nextState) == tranState.end()) {
                return false;
            }

            state = nextState; // 状态转换
        }

        auto tranState = state_machine[state];
        return tranState.find("end") != tranState.end(); // 判断能否结束
    }
};