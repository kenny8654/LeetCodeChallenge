/**
Runtime: 15 ms, faster than 52.97% of C++ online submissions for Combination Sum.
Memory Usage: 12.6 MB, less than 44.73% of C++ online submissions for Combination Sum.
**/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret= {};
        std::sort(candidates.begin(), candidates.end());
        DFS(candidates, target, 0, vector<int>{}, ret);
        return ret;
    }
    
    void DFS(vector<int>& candidates, int target, int index, vector<int> vec, vector<vector<int>>& ret){
        for(int i=index; i<candidates.size(); i++){
            vec.push_back(candidates[i]);
            if(target-candidates[i] < 0) return;
            if(target-candidates[i] == 0){
                ret.push_back(vec);
                return;
            }
            DFS(candidates, target-candidates[i], i, vec, ret);
            vec.pop_back();
        }
    }
};
