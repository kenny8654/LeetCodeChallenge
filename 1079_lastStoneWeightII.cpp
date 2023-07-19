/**
Runtime: 6ms
Beats 67.55%of users with C++
Memory: 8.31mb
Beats 63.04%of users with C++
  **/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if(stones.size() == 1)
            return stones[0];

        int ret = INT_MAX;
        int size = stones.size();
        int sum = 0;
        for(auto &stone:stones){
            sum += stone;
        }
        vector<vector<bool>> dp(size+1, vector<bool>(sum+1, false));
        // init dp
        for(int i=0; i<size; i++)
            dp[i][0] = true;
        
        // fill dp
        for(int i=1; i<=size; i++){
            for(int j=1; j<=sum; j++){
                if(j-stones[i-1] >= 0)
                    dp[i][j] = dp[i-1][j-stones[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        // calculate diff
        for(int i=sum/2; i>=0; i--){
            if(dp[size][i]){
                ret = min(ret, sum-2*i);
            }
        }
        return ret;
    }
};
