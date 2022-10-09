/**
Runtime: 127 ms, faster than 87.54% of C++ online submissions for Maximum Subarray.
Memory Usage: 70.5 MB, less than 6.22% of C++ online submissions for Maximum Subarray.
**/
#define INTMIN -10000
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        if(nums.size()==1) return ret;
        vector dp(nums.size(), INTMIN);
        dp[0]= nums[0];
        for(int i=1; i< nums.size(); i++){
            dp[i] = max(nums[i],dp[i-1]+nums[i]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
