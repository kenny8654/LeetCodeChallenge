/*
Runtime: 0 ms, Beats: 100%
Memory: 7.8 MB, Beats: 92.89%
*/
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ret = 0;
        vector<int> diffs;
        for(auto& cost:costs){
            ret += cost[0];
            diffs.push_back(cost[1]-cost[0]);
        }
        sort(diffs.begin(), diffs.end());
        for(int i=0; i<diffs.size()/2; i++){
            ret += diffs[i];
        }
        return ret;
    }
};
