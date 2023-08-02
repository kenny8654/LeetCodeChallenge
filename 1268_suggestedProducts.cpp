/**
Runtime: 37ms
Beats 94.68%of users with C++
Memory: 29.47mb
Beats 71.19%of users with C++
  **/
#define SUGGEST_SIZE 3
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ret;
        vector<string> tmp;
        string str;
        sort(products.begin(), products.end());
        for(auto c:searchWord){
            tmp.clear();
            str += c;
            auto it = lower_bound(products.begin(), products.end(), str);
            for(int i=0; i<SUGGEST_SIZE && it+i!=products.end(); i++){
                auto cur_str = *(it+i);
                if(cur_str.find(str) != 0)
                    break;
                tmp.push_back(cur_str);
            }
            ret.emplace_back(tmp);
        }
        return ret;
    }
};
