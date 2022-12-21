/**
Runtime: 216 ms, Beats: 5.2%
Memory: 16.1 MB, Beats: 9.98%
**/
class Solution {
public:
    int mNumCourses;
    int isCycle = false;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        mNumCourses = numCourses;
        vector<int> ret;
        vector<int> check(numCourses, -1); //-1:init, 0:visited, 1:added to ret
        vector<vector<bool>> graph(numCourses, vector<bool>(numCourses, false));

        for(auto& prerequisites:prerequisites){
            graph[prerequisites[1]][prerequisites[0]] = true;
        }

        for(int i=0; i<numCourses; i++)
            DFS(i, graph, check, ret);
        
        if(isCycle)
            ret.resize(0);
        reverse(ret.begin(), ret.end());
        return ret;
    }

    void DFS(int idx, vector<vector<bool>>& graph, vector<int>& check, vector<int>& ret){
        if(check[idx] == 0){
            isCycle = true;
            return;
        }
        if(check[idx] == 1)
            return;

        for(int i=0; i<mNumCourses; i++){
            if(graph[idx][i]){
                check[idx] = 0;
                DFS(i, graph, check, ret);
            }
        }
        ret.push_back(idx);
        check[idx] = 1;
    }
};
