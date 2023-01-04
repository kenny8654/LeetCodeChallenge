/**
Runtime: 143 ms, Beats: 86.99%
Memory: 9.7 MB, Beats: 87.7%
**/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
#if 0
        int half = 0;
        for(auto& num:nums){
            half += num;
        }
        if(half % 2) 
            return false;
        else{
            half /= 2;
            vector<bool> dp(half+1, false);
            dp[0] = true;
            for(auto& num:nums){
                for(int i=dp.size()-1; i>=num; i--){
                    dp[i] = dp[i] || dp[i-num];
                }
            }
            return dp[half];
        }
    
#else
        int half = 0;
        for(auto& num:nums){
            half += num;
        }
        if(half & 1)
            return false; 
        bitset<20001> bs(1);
        for(auto& num:nums){
            bs |= bs << num;
        }
        return bs[half/2];

#endif
    }
};
