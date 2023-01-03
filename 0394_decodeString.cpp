/**
Runtime: 0 ms, Beats: 100%
Memory: 6.1 MB, Beats: 99.75%
**/
class Solution {
public:
    string decodeString(string s) {
        string ret;;
        stack<char> st;
        for(auto& c:s){
            if(c == ']'){
                string tmp = "";
                while(st.top() != '['){
                    tmp = st.top() + tmp;
                    st.pop();
                }
                st.pop();
                int digit = 1;
                int num = 0; 
                while(!st.empty() && isdigit(st.top())){
                    num = num + digit * int(st.top()-'0');
                    digit *= 10;
                    st.pop();
                }
                while(num--){
                    for(auto& t:tmp)
                        st.push(t);
                }
            }else{
                st.push(c);
            }
        }

        while(!st.empty()){
            ret += st.top();
            st.pop();
        }
        reverse(ret.begin(), ret.end()); 
        return ret;
    }
};
