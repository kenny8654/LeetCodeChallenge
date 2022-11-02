/**
Runtime: 612 ms, faster than 77.98% of C++ online submissions for Non-overlapping Intervals.
Memory Usage: 89.9 MB, less than 20.17% of C++ online submissions for Non-overlapping Intervals.
**/
class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ret = 0, num=INT_MIN;
        sort(intervals.begin(), intervals.end(), comp);
        for(auto& vec:intervals){
            if(vec[0] >= num)
                num = vec[1];
            else
                ret++;
            
        }
        return ret;
    }
};
