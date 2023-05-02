/**
Runtime: 242 ms, Beats: 40.45%
Memory: 33.2 MB, Beats: 96.63%
**/
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ret = "";
        string cur = "";
        unordered_set<string> us;
        for(auto &word:dictionary){
            us.insert(word);
        }
        for(int i=0; i<sentence.size(); i++){
            cur += sentence[i];
            if(sentence[i] == ' ' || i == sentence.size()-1){
                ret += cur;
                cur = "";
            }else if(us.count(cur)){
                ret += cur + " ";
                cur = "";
                while(i<sentence.size() && sentence[++i] != ' ')
                    ;
            }
        }
        if(ret.back() == ' ')
            ret.pop_back();
        return ret;
    }
};
