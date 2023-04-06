/**
Runtime: 10 ms, Beats: 83.33%
Memory: 9 MB, Beats: 29.23%
**/
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == 0)
            return num;
        if(num.size() == k)
            return "0";

        string ret;
        stack<char> st;
        for(auto &c:num){
            while(st.size() && k && st.top()>c){
                k--;
                st.pop();
            }
            st.push(c);
        }

        while(k--)
            st.pop();
        
        while(!st.empty()){
            ret.push_back(st.top());
            st.pop();
        }
        while(ret.back() == '0')
            ret.pop_back();

        reverse(ret.begin(), ret.end());  
        return ret.size()==0? "0": ret;
    }
};
