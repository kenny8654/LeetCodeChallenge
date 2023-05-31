/**
Runtime: 203 ms, Beats: 36.64%
Memory: 50.9 MB, Beats: 31.13%
**/
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int ret = 0;
        unordered_map<string, int> dp; //word - cnt
        sort(words.begin(), words.end(), comp);
        for(auto& word:words){
            for(int i=0; i<word.size(); i++){
                string sub = word.substr(0,i) + word.substr(i+1);
                dp[word] = max(dp[word], dp[sub]+1);
                ret = max(ret, dp[word]);
            }
        }
        return ret;
    }
    const static bool comp(string& a, string& b){
        return a.size() < b.size();
    }
};
