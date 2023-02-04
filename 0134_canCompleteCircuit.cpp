/**
Runtime: 134 ms, Beats: 9.16%
Memory: 108.7 MB, Beats: 5.1%
**/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ret(0), sum(0), curr_min(INT_MAX);
        int size = gas.size();
        for(int i=0; i<size; i++){
            sum += gas[i] - cost[i];
            if(sum < curr_min){
                curr_min = sum;
                ret = i + 1;
            }
        }
        return (sum < 0)? -1: (ret % size);
    }
};
