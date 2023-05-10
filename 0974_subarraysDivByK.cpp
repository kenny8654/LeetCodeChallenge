/**
Runtime: 71 ms, Beats: 28.39%
Memory: 31.5 MB, Beats: 69.57%
**/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ret = 0;
        int sum = 0;
        unordered_map<int, int> um;

        um[0] = 1;
        for(auto& num:nums){
            sum += num;
            int remainder = sum % k;
            if(remainder < 0)
                remainder += k;
                
            if(um.count(remainder)){
                ret += um[remainder];
                um[remainder]++;
            }else
                um[remainder] = 1;

        }
        return ret;
    }
};
