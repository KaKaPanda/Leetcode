class Solution {
private:
    int version2number(string version) {
        int ans = 0;
        for (int i = 0; i < version.size(); ++i) {
            ans = ans * 10 + (version[i] - '0');
        }
        return ans;
    }

public:
    int compareVersion(string version1, string version2) {
        int sz1 = version1.size(), sz2 = version2.size();
        for (int i = 0, j = 0; i < sz1 || j < sz2; ) {
            int pos_i = version1.find('.', i);
            int pos_j = version2.find('.', j);
            pos_i = (pos_i == std::string::npos) ? sz1 : pos_i; // 需要判断pos是否有效
            pos_j = (pos_j == std::string::npos) ? sz2 : pos_j;

            int ver1 = version2number(version1.substr(i, pos_i-i));
            int ver2 = version2number(version2.substr(j, pos_j-j));
            if (ver1 < ver2) return -1;
            if (ver1 > ver2) return 1;
            
            i = min(sz1, pos_i + 1);
            j = min(sz2, pos_j + 1);
        }
        return 0;
    }
};