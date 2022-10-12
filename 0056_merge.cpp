/**
Runtime: 40 ms, faster than 93.54% of C++ online submissions for Merge Intervals.
Memory Usage: 20.2 MB, less than 16.03% of C++ online submissions for Merge Intervals.
**/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end());
        for(auto interval:intervals){
            if(ret.empty())ret.push_back(interval);
            if(interval[0]<=ret.back()[1])
                ret.back()[1] = max(ret.back()[1],interval[1]);
            else
                ret.push_back(interval);
        }
        return ret;
    }
};
