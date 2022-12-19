/**
Runtime: 10 ms, Beats: 82.1%
Memory: 11.3 MB, Beats: 53.63%
**/
class Solution {
public:
    static bool compare(string a, string b){
        string ab = a+b;
        string ba = b+a;
        return ab.compare(ba) > 0;
    }

    string largestNumber(vector<int>& nums) {
        string ret = "";
        vector<string> strs;

        for(auto& num:nums){
            auto str = std::to_string(num);
            strs.emplace_back(str);
        }
        sort(strs.begin(), strs.end(), compare);
        if(strs[0] == "0")
            return "0";
            
        for(auto& str:strs)
            ret += str;
        return ret;
    }
};
