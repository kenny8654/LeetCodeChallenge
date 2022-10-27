/**
Runtime: 19 ms, faster than 97.06% of C++ online submissions for Card Flipping Game.
Memory Usage: 19.5 MB, less than 75.74% of C++ online submissions for Card Flipping Game.
**/
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int ret = INT_MAX;
        unordered_set<int> s;
        for(int i=0; i<fronts.size(); i++)
            if(fronts[i] == backs[i]) s.insert(fronts[i]);
        
        
        for(auto& num:fronts)
           if(s.count(num) == 0) ret = min(ret, num);
        for(auto& num:backs)
           if(s.count(num) == 0) ret = min(ret, num);
        return (ret==INT_MAX)?0:ret;
    }
};
