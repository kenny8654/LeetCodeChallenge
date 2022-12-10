/**
Runtime: 141 ms, Beats: 80.86%
Memory: 47.4 MB, Beats: 30.99%
**/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int> > pq;

        for(auto& num:nums){
            pq.push(num);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
