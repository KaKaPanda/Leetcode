class Solution {
public:
    // a -> b!
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, std::unordered_set<int>> course_unlock_list; // 记录课程可以解锁的列表
        std::unordered_map<int, int> course_locked_map; // 记录课程有多少个依赖项
        std::unordered_set<int> course_unlocking;

        for (auto & item : prerequisites) {
            if (item.size() != 2) continue;
            course_unlock_list[item[1]].insert(item[0]);
            ++course_locked_map[item[0]];
        }

        for (int i = 0; i < numCourses; ++i) {
            if (course_locked_map[i] != 0) continue;
            course_unlocking.insert(i);
            course_locked_map.erase(i); // 注意要删除元素
        }

        vector<int> course_list;
        while (!course_unlocking.empty()) {
            for (auto & item : course_unlocking) {
                course_list.emplace_back(item);
                for (auto & course : course_unlock_list[item]) {
                    --course_locked_map[course];
                }
            }

            course_unlocking.clear();
            for (auto iter = course_locked_map.begin(); iter != course_locked_map.end(); ) {
                if (iter->second != 0) {
                    ++iter;
                    continue;
                }
                course_unlocking.insert(iter->first);
                iter = course_locked_map.erase(iter); // 注意要删除元素
            }
        }
        return course_list.size() == numCourses ? course_list : vector<int>{};
    }
};