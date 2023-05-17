/**
Runtime: 59 ms, Beats: 83.75%
Memory: 31 MB, Beats: 81.56%
**/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int ret = 0;
        int totalWeight = 0;
        for(auto& weight:weights){
            ret = max(ret, weight);
            totalWeight += weight;
        }

        while(ret < totalWeight){
            int midWeight = (totalWeight + ret) / 2;
            int currDay = 1;
            int currWeight = 0;
            for(auto& weight:weights){
                currWeight += weight;
                if(currWeight > midWeight){
                    currWeight = weight;
                    currDay++;
                }
            }
            if(currDay > days)
                ret = midWeight + 1;
            else
                totalWeight = midWeight;
        }
        return ret;
    }
};
