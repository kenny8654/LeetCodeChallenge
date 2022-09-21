/**
Runtime: 10 ms, faster than 87.96% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 6.8 MB, less than 96.75% of C++ online submissions for Longest Substring Without Repeating Characters.
**/

#define ASCINUM 127
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int ans=0, l=0;
      int map[ASCINUM];
      memset(map, -1, ASCINUM * sizeof(int));
      for(int r=0; r<s.size(); r++){
        if(map[int(s[r])] != -1)
          l = max(l, map[int(s[r])]+1);
        ans = max(ans, r-l+1);
        map[int(s[r])] = r;
      }
      return ans;
    }
};

