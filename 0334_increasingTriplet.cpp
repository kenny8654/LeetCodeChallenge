/**
Runtime: 120 ms, Beats: 65.29%
Memory: 109.7 MB, Beats: 6.34%
**/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int nFirst = INT_MAX, nSecond = INT_MAX;
        for(auto& num:nums){
            if(num <= nFirst) 
                nFirst = num;
            else if(num <= nSecond) 
                nSecond = num;
            else
                return true;
        }
        return false;
    }
};
