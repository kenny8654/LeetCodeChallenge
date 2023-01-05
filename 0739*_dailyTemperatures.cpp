/**
Runtime: 668 ms, Beats: 5%
Memory: 103.8 MB, Beats: 25.57%
**/
class Solution {
public:
    struct day{
        int temperature;
        int idx;
        bool operator<(const day& d) const{
            return temperature > d.temperature;
        }
    };

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);
        priority_queue<day> pq;
        pq.push(day{temperatures[0], 0});

        for(int i=1; i<temperatures.size(); i++){
            pq.push(day{temperatures[i], i});
            while(pq.top().temperature != temperatures[i]){
                ret[pq.top().idx] = i - pq.top().idx;
                pq.pop();
            }
        }
        return ret;
    }
};
