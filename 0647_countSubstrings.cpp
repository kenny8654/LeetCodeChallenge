/**
Runtime: 6 ms, faster than 78.67% of C++ online submissions for Palindromic Substrings.
Memory Usage: 6.4 MB, less than 64.39% of C++ online submissions for Palindromic Substrings.
**/
class Solution {
public:
    int countSubstrings(string s) {
        vector<int> dp(s.size(), 0);
        dp[0] = 1;
        for(int i=1; i<s.size(); i++){
            int l=i-1, r=i+1;
            dp[i] = dp[i-1] + 1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                l--; r++;
                dp[i]++;
            }
            l=i-1, r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                l--; r++;
                dp[i]++;
            }
        }
        return dp[s.size()-1];
    }
};
