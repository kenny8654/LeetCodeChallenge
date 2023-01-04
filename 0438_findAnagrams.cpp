/**
Runtime: 16 ms, Beats: 80.31%
Memory: 8.6 MB, Beats: 90.21%
**/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int l=0, r=0;
        vector<int> vec_p(26, 0);
        vector<int> vec_s(26, 0);
        for(auto& c:p){
            vec_p[int(c-'a')]++;
        }

        for(; r<s.size(); r++){
            int idx = int(s[r]-'a');
            vec_s[idx]++;
            while(vec_s[idx] > vec_p[idx]){
                vec_s[int(s[l]-'a')]--;
                l++;
            }
            if(vec_p == vec_s)
                ret.emplace_back(l);
        }

     
        return ret;
    }
};
