/**
Runtime: 16 ms, faster than 92.73% of C++ online submissions for Top K Frequent Elements.
Memory Usage: 13.8 MB, less than 26.13% of C++ online submissions for Top K Frequent Elements.
**/
class Solution {
public:
    static bool comp(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> map;
        for(int num:nums)
            map[num] += 1;
        
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), comp);
        for(int i=0; i<k; i++)
            ret.emplace_back(vec[i].first);
        
        return ret;
    }
    
    
};
