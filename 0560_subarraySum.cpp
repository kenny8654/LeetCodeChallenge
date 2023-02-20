/**
Runtim: 95 ms, Beats: 71.33%
Memory: 41.3 MB, Beats: 96.69%
**/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap; // sum - count
        int sum(0), ret(0);
        
        umap[0] = 1;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(umap.count(sum - k))
                ret += umap[sum - k];
            umap[sum] += 1;
        }
        return ret;    
    }
};
