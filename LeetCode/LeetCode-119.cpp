class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;

        while (rowIndex-- >= 0) {
            if (row.empty()) {
                row.emplace_back(1);
                continue;
            }

            for (int i = row.size()-1; i >= 1; --i) {
                row[i] += row[i-1];
            }
            row.emplace_back(1);
        }
        return row;
    }
};