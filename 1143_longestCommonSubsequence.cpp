/**
Runtime: 6 ms, Beats: 99.81%
Memory: 10.7 MB, Beats: 70.68%
**/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int row = text1.size(), col = text2.size();
        int dp[row][col];
        dp[0][0] = (text1[0]==text2[0])?1: 0;
        for(int j=1; j<col; j++)
            dp[0][j] = (text1[0]==text2[j])?1:dp[0][j-1];
        for(int i=1; i<row; i++)
            dp[i][0] = (text1[i]==text2[0])?1:dp[i-1][0];
        

        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(text1[i] == text2[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[row-1][col-1];
    }
};
