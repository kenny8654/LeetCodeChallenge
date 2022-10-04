/**
Runtime: 8 ms, faster than 33.38% of C++ online submissions for Permutations.
Memory Usage: 8.5 MB, less than 10.83% of C++ online submissions for Permutations.
**/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        DFS(nums, 0, {}, ret);
        return ret;
    }
    
    void DFS(vector<int>& nums, int flag, vector<int> vec, vector<vector<int>>& ret){
        if(flag == pow(2, nums.size())-1){
            ret.push_back(vec);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if((flag & (int)pow(2,i)) == 0){
                vec.push_back(nums[i]);
                flag += pow(2,i);
                DFS(nums, flag, vec, ret);
                vec.pop_back();
                flag -= pow(2,i);
            }
            
        }
    }
};
