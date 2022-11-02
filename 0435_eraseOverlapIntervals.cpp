/**
Runtime: 303 ms, faster than 100.00% of C++ online submissions for Non-overlapping Intervals.
Memory Usage: 90.7 MB, less than 17.68% of C++ online submissions for Non-overlapping Intervals.
**/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ret = 0, num=INT_MIN;
        int n = intervals.size();
        
        pair<int,int> p[n];
        for(int i=0;i<n;i++){
            p[i].first = intervals[i][0];
            p[i].second = intervals[i][1];
        }
        
        sort(p, p+n, [](pair<int,int> &vp1, pair<int,int> &vp2){return vp1.second<vp2.second;});
        for(auto& [num1, num2]:p){
            if(num1 >= num)
                num = num2;
            else
                ret++;
        }
        return ret;
    }
};
