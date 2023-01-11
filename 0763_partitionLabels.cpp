/**
Runtime: 0 ms, Beats: 100%
Memory: 6.9 MB, Beats: 27.86%
**/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ret;
        unordered_map<char, int> umap;
        for(int i=0; i<s.size(); i++){
            umap[s[i]] = max(umap[s[i]], i);
        }

        int cur_left = 0;
        int cur_right = 0;
        for(int i=0; i<s.size(); i++){
            cur_right = max(cur_right, umap[s[i]]);
            if(cur_right == i){
                ret.push_back(cur_right-cur_left+1);
                cur_left = cur_right + 1;
            }
        }
        return ret;
    }
};
