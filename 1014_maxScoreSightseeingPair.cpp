/**
Runtime: 49 ms, Beats: 92%
Memory: 40.8 MB, Beats: 78.87%
**/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ret = 0;
        int score = 0;
        for(auto& value: values){
            ret = max(ret, score + value);
            score = max(score, value) - 1;
        }
        return ret;
    }
};
