/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
Memory Usage: 6.4 MB, less than 81.76% of C++ online submissions for Letter Combinations of a Phone Number.
**/
//DFS
unordered_map<char, string> letter({{'2',"abc"},{'3',"def"},{'4',"ghi"},
    {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}});

class Solution {
public:
    void combine(vector<string> &ret, string &digits, int pos, string s){
      if(pos == digits.size()) ret.push_back(s);
      string tmp = letter[digits[pos]];
      for(char c:tmp)
        combine(ret, digits, pos+1, s+c);      
    }
  
    vector<string> letterCombinations(string digits) {
      if(digits.size() == 0) return {};
      vector<string> ret = {};
      combine(ret, digits, 0, "");
      return ret;
    }
};