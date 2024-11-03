class Solution {
public:
    // 检查依赖数据中是否存在环形
    // [[1,0],[1,2],[0,1]] 使用 std::unordered_map<int, int> 会被覆盖
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, std::unordered_set<int>> cur_dep_map;
        
        for (auto & courses : prerequisites) {
            // if (courses.size() != 2) continue;

            cur_dep_map[courses[0]].insert(courses[1]);

            auto depends_ptr = cur_dep_map.find(courses[1]);
            if (depends_ptr == cur_dep_map.end()) continue;

            std::unordered_set<int> course_set = depends_ptr->second;
            if (course_set.find(courses[0]) != course_set.end()) return false;

            while (!course_set.empty()) { // 广度优先搜索
                std::unordered_set<int> course_nex;
                for (auto & course : course_set) {
                    depends_ptr = cur_dep_map.find(course);
                    if (depends_ptr != cur_dep_map.end()) {
                        auto dep_courses = depends_ptr->second;
                        if (dep_courses.find(courses[0]) != dep_courses.end()) return false;
                        course_nex.insert(dep_courses.begin(), dep_courses.end());
                    }
                }
                course_set = std::move(course_nex);
            }
            
        }
        return true;
    }
};