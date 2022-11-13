/**
Runtime: 0 ms, Beats: 100%
Memory: 8 MB, Beats: 19.2%
**/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
        return max(rob(nums, 0, nums.size()-2), rob(nums, 1, nums.size()-1));
    }

    int rob(vector<int>& nums, int l, int r){
        vector<int> dp(nums.size(), 0);
        dp[l] = nums[l];
        dp[l+1] = max(nums[l], nums[l+1]);
        for(int i=l+2; i<=r; i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[r];
    }
};
