/**
Runtime: 280 ms, faster than 83.21% of C++ online submissions for Number of Matching Subsequences.
Memory Usage: 34.9 MB, less than 97.97% of C++ online submissions for Number of Matching Subsequences.
**/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ret=0;
        for(string word: words)
            checkMatchingSubseq(s, word, ret);
        return ret;
    }
    
    void checkMatchingSubseq(string& s, string& word, int& ret){
        int index = 0;
        for(char c:word){
            index = s.find(c, index);
            if(index == string::npos) return;
            index++;
        }
        ret++;
    }
};
