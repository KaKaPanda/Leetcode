class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> fill_from_left = height, fill_from_right = height;

        int highest = 0;
        for (int i = 0; i < fill_from_left.size(); ++i) {
            if (fill_from_left[i] > highest) {
                highest = fill_from_left[i];
            } else {
                fill_from_left[i] = highest;
            }
        }

        highest = 0;
        for (int i = height.size() - 1; i >= 0; --i) {
            if (fill_from_right[i] > highest) {
                highest = fill_from_right[i];
            } else {
                fill_from_right[i] = highest;
            }
        }

        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            int lower = (fill_from_left[i] > fill_from_right[i])? fill_from_right[i] : fill_from_left[i];
            res += lower - height[i];
        }
        return res;
    }
};