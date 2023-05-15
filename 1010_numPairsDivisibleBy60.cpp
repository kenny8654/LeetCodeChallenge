/**
Runtime: 39 ms: Beats: 75.11%
Memory: 28 MB, Beats 89.89%
**/
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ret = 0;
        vector<int> dp(60, 0);

        for(auto& t:time){
            int t_div = t % 60;
            int t_remain = (60 - t_div) % 60;
            ret += dp[t_remain];
            dp[t_div]++;
        }
        return ret;
    }
};
