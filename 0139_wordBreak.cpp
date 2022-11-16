/**
Runtime: 4 ms, Beats: 92.62%
Memory: 7.6 MB, Beats: 88.15%
**/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        
        for(int i=1; i<dp.size(); i++){
            for(auto& word:wordDict){
                if(dp[i-1] == true && s.substr(i-1, word.size()) == word){
                    dp[i+word.size()-1] = dp[i-1];
                }
            }
        }
        return dp[dp.size()-1];
    }
};
