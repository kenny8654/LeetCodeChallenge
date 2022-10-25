/**
Runtime: 24 ms, faster than 95.07% of C++ online submissions for Product of Array Except Self.
Memory Usage: 23.8 MB, less than 96.59% of C++ online submissions for Product of Array Except Self.
**/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);
        int tmp=1;
        for(int i=0; i<nums.size(); i++){
            ret[i] *= tmp;
            tmp *= nums[i];
        }
        tmp=1;
        for(int i=nums.size()-1; i>=0; i--){
            ret[i] *= tmp;
            tmp *= nums[i];
        }
        return ret;
    }
};
