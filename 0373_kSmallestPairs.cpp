/**
Runtime: 304 ms, Beats: 71.57%
Memory: 119.3 MB, Beats: 22.60%
**/
#define pi pair<int, pair<int, int>> 
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ret;
        priority_queue<pi, vector<pi>, greater<pi>> pq; // {sum, {idx1, idx2}}

        for(int i=0; i<nums1.size(); i++){
            pq.push({nums1[i]+nums2[0], {i, 0}});
        }

        while(!pq.empty() && k-->0){
            auto tmp = pq.top().second;
            pq.pop();
            ret.push_back({nums1[tmp.first], nums2[tmp.second]});

            if(tmp.second+1 < nums2.size())
                pq.push({nums1[tmp.first]+nums2[tmp.second+1], {tmp.first, tmp.second+1}});
        }
        return ret;
    }
};
