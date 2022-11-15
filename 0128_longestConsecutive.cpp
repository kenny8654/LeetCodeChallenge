/**
Runtime: 181 ms, Beats: 81.31%
Memory: 52.1 MB, Beats: 11.1%
**/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, int> map;

        for(auto i:nums){
            if(map[i] != 0) continue;
            if(map[i-1] == 0 && map[i+1] == 0){
                map[i] = 1;
            }else{
                map[i] = map[i-1] + map[i+1] + 1;
                map[i-map[i-1]] = map[i+map[i+1]] = map[i];
            }
            ret = max(ret, map[i]);
        }
        return ret;
    }
};
