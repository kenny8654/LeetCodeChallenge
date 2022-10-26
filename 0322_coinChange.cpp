/**
Runtime: 135 ms, faster than 68.19% of C++ online submissions for Coin Change.
Memory Usage: 14.6 MB, less than 56.45% of C++ online submissions for Coin Change.
**/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for(int i=1; i<dp.size(); i++){
            for(int j=0; j<coins.size(); j++){
                if(i-coins[j] < 0) break;
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
        return (dp[amount]==amount+1)?-1:dp[amount];
    }
};
