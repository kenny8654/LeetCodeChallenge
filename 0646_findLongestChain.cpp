/**
Runtime: 62 ms, Beats: 90.7%
Memory: 23.8 MB, Beats: 39.28%
**/
#define pii pair<int, int>
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int ret = 1;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(auto &pair:pairs){
            pq.push({pair[1], pair[0]});
        }

        int cur_max = pq.top().first;
        pq.pop();
        while(!pq.empty()){
            if(pq.top().second > cur_max){
                ret++;
                cur_max = pq.top().first;
            }
            pq.pop();
        }
        return ret;
    }
};
