/**
Runtime: 12 ms, faster than 80.11% of C++ online submissions for Longest Repeating Character Replacement.
Memory Usage: 7.2 MB, less than 13.08% of C++ online submissions for Longest Repeating Character Replacement.
**/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ret=0, size=s.size(), l=0, maxMapSize=0;
        unordered_map<char, int> map;
        for(int r=0; r<s.size(); r++){
            map[s[r]]++;
            maxMapSize = max(maxMapSize, map[s[r]]);
            if(r-l+1-maxMapSize > k) {
                map[s[l]]--;
                l++;
            }
            else ret = max(ret,r-l+1);
        }
        return ret;
    }
};
