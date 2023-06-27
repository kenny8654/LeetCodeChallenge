/**
Runtime: 14 ms, Beats: 76.57%
Memory: 10.4 MB, Beats: 60.19%
**/
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> vec;
        int last_place;
        for(int i=0; i<trips.size(); i++){
            vec.push_back({trips[i][1], -trips[i][0]});
            vec.push_back({trips[i][2], trips[i][0]});
        }
        sort(vec.begin(), vec.end());
        for(int i=0; i<vec.size(); i++){
            capacity += vec[i].second;
            if(capacity < 0 && i+1 <= vec.size() && vec[i].first != vec[i+1].first)
                return false;
        }
        return true;
    }
};
