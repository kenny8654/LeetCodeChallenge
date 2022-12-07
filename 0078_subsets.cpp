/**
Runtime: 0 ms, Beats: 100%
Memory: 15.9 MB, Beats: 31.44%
**/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> vec;
        DFS(nums, ret, 0, vec);
        return ret;
    }

    void DFS(vector<int>& nums, vector<vector<int>>& ret, int idx, vector<int> vec){
        if(idx == nums.size()){
            ret.push_back(vec);
            return;
        }
        DFS(nums, ret, idx+1, vec);
        vec.push_back(nums[idx]);
        DFS(nums, ret, idx+1, vec);
    }
};
