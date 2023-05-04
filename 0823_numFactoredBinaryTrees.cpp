/**
Runtime: 90 ms, Beats: 43.18%
Memory: 9.2 MB, Beats: 55%
**/
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long ret = 0;
        const int mod = pow(10,9) + 7;
        unordered_map<int, long> dp; // num -  num of binary trees it can make
        sort(arr.begin(), arr.end());
        for(auto num:arr){
            dp[num] = dfs(arr, dp, num);
        }

        for(auto pair:dp){
            ret = (ret + pair.second) % mod;
        }
        return (int)ret;
    }

    long dfs(vector<int>& arr, unordered_map<int, long>& dp, int num){
        if(dp.find(num) != dp.end()){
            return dp[num];
        }else{
            long ret = 0;
            for(auto pair:dp){
                int leaf1 = pair.first;
                int leaf2 = num / leaf1;
                if(num%leaf1 == 0 && dp.find(leaf2) != dp.end()){
                    ret += dp[leaf1]*dp[leaf2];
                }
            }
            return ret + 1;
        }
    }
};
