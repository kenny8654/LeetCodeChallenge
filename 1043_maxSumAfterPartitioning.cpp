/**
Runtime: 13 ms, Beats: 88.59%
Memory: 8.6 MB, Beats: 61.68%
**/
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), 0);
        int curr_max = INT_MIN;
        for(int i=0; i<k; i++){
            curr_max = max(curr_max, arr[i]);
            dp[i] = curr_max*(i+1);
        }
        for(int i=k; i<arr.size(); i++){
            curr_max = arr[i];
            for(int len=1; len<=k; len++){
                curr_max = max(curr_max, arr[i-len+1]);
                dp[i] = max(dp[i], dp[i-len]+curr_max*len);
            }
        }
        return dp.back();
    }
};
