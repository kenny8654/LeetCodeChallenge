/**
Runtime: 113 ms, faster than 96.65% of C++ online submissions for Maximum Subarray.
Memory Usage: 67.7 MB, less than 90.32% of C++ online submissions for Maximum Subarray.
**/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0], curr=nums[0];
        if(nums.size()==1) return ret;
        for(int i=1; i< nums.size(); i++){
            curr = max(nums[i], curr+nums[i]);
            ret = max(ret, curr);
        }
        return ret;
    }
};
