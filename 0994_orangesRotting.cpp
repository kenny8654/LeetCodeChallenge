/**
Runtime: 3 ms, Beats: 97.66%
Memory: 13 MB, Beats: 83.81%
**/
class Solution {
public:
    int rowSize, colSize, freshCnt;
    int orangesRotting(vector<vector<int>>& grid) {
        int ret = 0;
        freshCnt = 0;
        rowSize = grid.size();
        colSize = grid[0].size();
        queue<pair<int, int>> queRotten;
        for(int i=0; i<rowSize; i++){
            for(int j=0; j<colSize; j++){
                if(grid[i][j] == 1)
                    freshCnt++;
                else if(grid[i][j] == 2)
                    queRotten.push({i,j});
            }
        }
        while(!queRotten.empty() && freshCnt){
            int queSize = queRotten.size();
            for(int i=0; i<queSize; i++){
                BFS(grid, queRotten);
            }
            ret++;
        }
        
        return (freshCnt)? -1: ret;
    }

    void BFS(vector<vector<int>>& grid, queue<pair<int, int>>& queRotten){
        static pair<int,int> directions[4] ={{1,0}, {0,1}, {-1,0}, {0,-1}}; 
        pair<int, int> cur_pos = queRotten.front();
        queRotten.pop();
     
        for(auto& direction:directions){
            pair<int, int> next_pos = {direction.first+cur_pos.first, direction.second+cur_pos.second};
            if(next_pos.first < 0 || next_pos.first >= rowSize ||
                  next_pos.second < 0 || next_pos.second >= colSize){
                continue;
            }
            if(grid[next_pos.first][next_pos.second] == 1){
                grid[next_pos.first][next_pos.second] = 2;
                freshCnt--;
                queRotten.push(next_pos);
            }
        }
    }
};
