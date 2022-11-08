/**
Runtime:0 ms, Beats: 100%
Memory: 6.7 MB, Beats: 29.13%
**/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 0;
        for(int& num:nums){
            if(num < dp.size())
                dp[num] = 1;
        }

        for(int i=1; i<dp.size(); i++){
            for(int j=0 ; j<nums.size(); j++){
                if(i-nums[j]>0){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }

         return dp[target];
    }
};
