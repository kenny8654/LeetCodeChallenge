/**
Runtime: 29 ms, Beats: 72.96%
Memory: 13.1 MB, Beats: 46.61%
**/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int row = text1.size(), col = text2.size();
        vector<vector<int>> dp(row, vector<int> (col, 0));
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
