/**
Runtime: 38 ms, faster than 92.18% of C++ online submissions for Group Anagrams.
Memory Usage: 20.6 MB, less than 56.75% of C++ online submissions for Group Anagrams.
**/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> map;
        for(string str:strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            map[tmp].emplace_back(str);
        }
        for(pair<string, vector<string>> element : map)
            ret.emplace_back(element.second);
        return ret;
    }
};
