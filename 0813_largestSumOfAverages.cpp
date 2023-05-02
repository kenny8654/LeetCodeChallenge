/**
Runtime: 21 ms, Beats: 55.78%
Memory: 7.8 MB, Beats: 80.90%
**/
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        vector<vector<double>> dp(nums.size(), vector<double>(k+1, -1));
        return dfs(nums, dp, k, 0);
    }

    double dfs(vector<int>& nums, vector<vector<double>>& dp, int k, int idx){
        if(idx == nums.size())
            return 0;
        if(k == 0)
            return INT_MIN;
        if(dp[idx][k] != -1)
            return dp[idx][k];
        
        double sum = 0, curr_max = INT_MIN;
        for(int i=idx; i<nums.size(); i++){
            sum += nums[i];
            curr_max = max(curr_max, sum/(i-idx+1) + dfs(nums, dp, k-1, i+1));
        }
        dp[idx][k] = curr_max;
        return dp[idx][k];
    }
};
