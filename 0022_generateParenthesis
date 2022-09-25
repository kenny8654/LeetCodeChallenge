/**
Runtime: 3 ms, faster than 88.02% of C++ online submissions for Generate Parentheses.
Memory Usage: 13.7 MB, less than 46.56% of C++ online submissions for Generate Parentheses.
**/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        DFS(0, 0, n, "", ret);
        return ret;
    }
    
    void DFS(int left, int right, int &n, string str, vector<string> &ret){
        if(str.length() == n*2) ret.push_back(str);
        if(left<n) DFS(left+1, right, n, str+'(', ret);
        if(right<n && left>right) DFS(left, right+1, n, str+')', ret);
    }
};
