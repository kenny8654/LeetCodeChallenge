/**
Runtime: 0 ms, Beats: 100%
Memory: 6.6 MB, Beats: 29.66%
**/
//DP
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(m, vector<int>(n, 1));

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
};

/**
Runtime: 0 ms, Beats: 100%
Memory: 6 MB, Beats: 79.61%
**/
// Math
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ret = 1;

        for(int i=1; i<n; i++){
            ret = ret * (m+i-1) / (i);
        }
        return (int) ret;
    }
};
