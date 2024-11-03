class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) return false;
        if (n1 == 0 || n2 == 0) return s1 + s2 == s3;

        vector<vector<int>> mat = vector<vector<int>>(n1+1, vector<int>(n2+1, 0));
        mat[0][0] = true;
        for (int i = 0; i <= n1; ++i) {
            for (int j = 0; j <= n2; ++j) {
                if (i == 0 && j == 0) continue;
                if (i > 0) {
                    mat[i][j] |= mat[i-1][j] && s1[i-1] == s3[i+j-1]; // 注意索引越界
                }
                if (j > 0) {
                    mat[i][j] |= mat[i][j-1] && s2[j-1] == s3[i+j-1];
                }

            }
        }
        return mat[n1][n2];
    }
};