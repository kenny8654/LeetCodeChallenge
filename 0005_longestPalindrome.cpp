/**
Runtime: 20 ms, faster than 84.46% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 6.8 MB, less than 97.60% of C++ online submissions for Longest Palindromic Substring.
**/
string str;
class Solution {
public:
    struct window{
        int left;
        int right;
    };
    
    window findPalindrome(window win){
        if(win.left-1 >= 0 && win.right+1 <=str.size()-1){
            if (str[win.left-1] == str[win.right+1]){
                win.left--;
                win.right++;
                return findPalindrome(win);
            }
            return win;
        }
        return win;
    }

    int gstWindowSize(window win){
        return win.right - win.left + 1;
    }
    
    string longestPalindrome(string s) {
        str = s;
        window ret;

        for(int i=0; i<s.size(); i++){
            int j = 0;
            while(i+j+1<s.size() && s[i] == s[i+j+1])
                j++;
            window tmp = findPalindrome(window{i, i+j});
            ret = (gstWindowSize(tmp)>gstWindowSize(ret)) ? tmp:ret;
        }
        return s.substr(ret.left, gstWindowSize(ret));
    }
};
