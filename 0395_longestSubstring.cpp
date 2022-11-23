/**
Runtime: 811 ms, Beats: 24.79%
Memory: 59.6 MB, Beats: 8.73%
**/
class Solution {
public:
    int longestSubstring(string s, int& k) {
        int n = s.size(), idx = 0;
        bool status = true;

        unordered_map<char, int> map;
        for(auto& c:s)
            map[c]++;
        for(idx=0; idx<n; idx++){
            if(map[s[idx]] < k){
                status = false;
                break;
            }
        }
    
        if(status)
            return n;
        else{
            return max(longestSubstring(s.substr(0, idx), k),
                       longestSubstring(s.substr(idx+1), k));
        }
    }
};
