/**
Runtime: 3 ms, Beats: 98.21%
Memory: 12.9 MB, Beats: 90.50%
**/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int min = prices[0];
        for(int i=1; i<prices.size(); i++){
            if(prices[i] < min){
                min = prices[i];
            }else if(prices[i] > min){
                ret += prices[i]-min;
                min = prices[i];
            }
        }
        return ret;
    }
};
