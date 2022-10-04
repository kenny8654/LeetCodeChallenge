/**
Runtime: 389 ms, faster than 36.22% of C++ online submissions for Jump Game II.
Memory Usage: 17.2 MB, less than 36.13% of C++ online submissions for Jump Game II.
**/
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for(int i=0; i<nums.size(); i++){
            for(int len=nums[i]; len>0; len--){
                if(i+len<nums.size())
                    dp[i+len] = min(dp[i+len], 1+dp[i]);
            }
        }
        return dp[nums.size()-1];
    }
};
