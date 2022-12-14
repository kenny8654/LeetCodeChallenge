/**
Runtime: 23 ms, Beats: 61.13%
Memory: 12.8 MB, Beats: 9.73%
**/
class Solution {
public:
    int calculate(string s) {
        vector<int> vNum;
        vector<bool> vAdd; //true:+, false:-
        int last_num = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' ')  continue;
            else if(s[i]=='/' || s[i] =='*'){
                bool isDivide = false;
                bool isAgain = false;
                if(s[i] == '/') 
                    isDivide = true;
                i++;
                int num = 0;
                for(; i<s.size(); i++){
                    if(s[i]==' ') continue;
                    else if(s[i]=='+'){
                        vAdd.push_back(true);
                        break;
                    }else if( s[i]=='-'){
                        vAdd.push_back(false);
                        break;
                    }else if(s[i]=='*' || s[i]=='/') {
                        isAgain = true;
                        i--;
                        break;
                    }
                    num = num*10 + int(s[i]-'0');
                }
                last_num = (isDivide)? last_num/num: last_num * num;
                if(!isAgain){
                    vNum.push_back(last_num);
                    last_num = 0;
                } 
            }else if(s[i]=='+'){
                vAdd.push_back(true);
                vNum.push_back(last_num);
                last_num = 0;
            }else if(s[i]=='-'){
                vAdd.push_back(false);
                vNum.push_back(last_num);
                last_num = 0;
            }else{
                last_num = last_num*10 + int(s[i]-'0');
            }
        }
        if(last_num)
            vNum.push_back(last_num);
        int ret = 0;
        if(vNum.size()) 
            ret = vNum[0];
        else 
            return 0;
        for(int i=1; i<vNum.size(); i++){
            ret = (vAdd[i-1])?  ret+vNum[i]: ret-vNum[i];
        }
        return ret;
    }
};
