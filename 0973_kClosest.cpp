/**
Runtime: 238 ms, Beats: 67.1%
Memory: 79.4 MB, Beats: 26.64%
**/
#define piv pair<int, vector<int>> 
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ret;
        vector<piv> vec;// distance - point
        for(auto& point:points)
            vec.push_back({point[0]*point[0]+point[1]*point[1], point});
        
        sort(vec.begin(), vec.end());
        for(int i=0; k--; i++)
             ret.push_back(vec[i].second);
        return ret;
    }
};
