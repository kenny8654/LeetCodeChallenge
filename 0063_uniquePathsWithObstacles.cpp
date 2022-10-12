/**
Runtime: 3 ms, faster than 87.48% of C++ online submissions for Unique Paths II.
Memory Usage: 7.9 MB, less than 13.65% of C++ online submissions for Unique Paths II.
**/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(),0));
        if(!obstacleGrid[0][0])
            dp[0][0] = 1;
        for(int i=0; i<obstacleGrid.size(); i++){
            for(int j=0; j<obstacleGrid[0].size(); j++){
                if(i==0 && j==0) continue;
                if(!obstacleGrid[i][j]){
                    dp[i][j] = ((i>0)?dp[i-1][j]:0) + ((j>0)?dp[i][j-1]:0);
                }
            }
        }    
        return dp.back().back();
    }
};
