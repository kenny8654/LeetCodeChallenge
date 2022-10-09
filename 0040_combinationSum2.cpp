/**
Runtime: 3 ms, faster than 96.07% of C++ online submissions for Combination Sum II.
Memory Usage: 11.6 MB, less than 25.21% of C++ online submissions for Combination Sum II.
**/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;       
        std::sort(candidates.begin(), candidates.end());
        BFS(candidates, target, 0, {}, ret);
        return ret;
    }
    
    void BFS(vector<int>& candidates, int target, int index, vector<int> vec, vector<vector<int>>& ret){
        if(target == 0) {ret.push_back(vec); return;}
        if(target < 0) return;
        for(int i=index; i<candidates.size(); i++){
            vec.push_back(candidates[i]);
            if(target-candidates[i]<0) return;
            BFS(candidates, target-candidates[i], i+1, vec, ret);
            while(i+1<candidates.size() && candidates[i+1]==vec.back()) i++;
            vec.pop_back();
        }
    }
};
