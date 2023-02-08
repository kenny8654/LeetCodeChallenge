/**
Runtime: 3 ms, Beats: 88.57%
Memory: 11.1 MB, Beats: 89.2%
**/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;

        vector<int> buy(prices.size(), 0);
        vector<int> sell(prices.size(), 0);
        buy[0] = -prices[0];
        sell[0] = 0;
        buy[1] = max(buy[0], -prices[1]);
        sell[1] = max(0, prices[1]-prices[0]);

        for(int i=2; i<prices.size(); i++){
            buy[i] = max(buy[i-1], sell[i-2]-prices[i]);
            sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
        }
        return sell.back();
    }
};
