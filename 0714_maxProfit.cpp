/**
Runtime: 105 ms, Beats: 91.80%
Memory: 54.8 MB, Beats: 99.35%
**/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int ret = 0;
        int buy = - prices[0];
        for(int i=1; i<prices.size(); i++){
            ret = max(ret, buy+prices[i]-fee);
            buy = max(buy, ret-prices[i]);
        } 
        return ret;
    }
};
