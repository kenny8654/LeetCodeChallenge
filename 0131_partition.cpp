/**
Runtime: 91 ms, Beats: 99.14%
Memory: 49.1 MB, Beats: 95.82%
**/
class Solution {
public:
    int size;
    vector<vector<string>> partition(string s) {
        size = s.size();
        vector<vector<string>> ret;
        vector<string> vec;
        findPalindrome(ret, s, 0, vec);
        return ret;
    }

    void findPalindrome(vector<vector<string>>& ret, string& s, int idx, vector<string>& vec){
        if(idx == size)
            ret.push_back(vec);
        else{
            for(int end=idx; end<size; end++){
                if(isPalindrome(s, idx, end)){
                    vec.push_back(s.substr(idx, end-idx+1));
                    findPalindrome(ret, s, end+1, vec);
                    vec.pop_back();
                }
            }
        }
        return;
    }

    bool isPalindrome(string& s, int l, int r){
        while(l<r){
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
};
