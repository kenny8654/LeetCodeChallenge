/**
Runtime: 28 ms, faster than 83.46% of C++ online submissions for Course Schedule.
Memory Usage: 14.3 MB, less than 42.66% of C++ online submissions for Course Schedule.
**/
class Solution {
public:
    bool isCycle(vector<int> graph[], vector<int>& isVisit, int idx){
        if(isVisit[idx] == 1){
            return true;
        }else if(isVisit[idx] == 0){
            isVisit[idx] = 1;
            for(auto course:graph[idx]){
                if(isVisit[idx]!= -1 && isCycle(graph, isVisit, course))
                    return true;
            }
        }
        isVisit[idx] = -1;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        for(auto prerequisite:prerequisites)
            graph[prerequisite[1]].emplace_back(prerequisite[0]);
        
        vector<int> isVisit(numCourses, 0); //-1:don't care, 1: visited, 0: not visited
        for(int i=0; i<numCourses; i++)
            if(isCycle(graph, isVisit, i)) return false;
        return true;
    }
};
