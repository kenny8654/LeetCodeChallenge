/**
Runtime: 113 ms, faster than 96.65% of C++ online submissions for Maximum Subarray.
Memory Usage: 67.7 MB, less than 90.32% of C++ online submissions for Maximum Subarray.
**/
#define INTMIN -1000000
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret=INTMIN, curr=INTMIN;
        for(int i=0; i< nums.size(); i++){
            curr = max(nums[i], curr+nums[i]);
            ret = max(ret, curr);
        }
        return ret;
    }
};
