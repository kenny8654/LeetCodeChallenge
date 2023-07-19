/**
Runtime: 7ms
Beats 82.64%of users with C++
Memory: 5.82mb
Beats 98.03%of users with C++
  **/
class Solution {
public:
    int numTilePossibilities(string tiles) {
        int ret = 0;
        sort(tiles.begin(), tiles.end());
        vector<bool> isVisited(tiles.size(), false);
        backTrack(tiles, isVisited, ret);
        return ret;
    }

    void backTrack(string& tiles, vector<bool>& isVisited, int& ret){
        for(int i=0; i<tiles.size(); i++){
            if(isVisited[i] || i>0 && tiles[i]==tiles[i-1] && isVisited[i-1]==false)
                continue;

            ret++;
            isVisited[i] = true;
            backTrack(tiles, isVisited, ret);
            isVisited[i] = false;
        }
    }
};
