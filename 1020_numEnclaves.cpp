/**
Runtime: 78 ms, Beats: 60.57%
Memory: 27.3 MB, Beats: 93.63%
**/
class Solution {
private:
    int rowsize;
    int colsize;
public:
    int (vector<vector<int>>& grid) {
        int ret = 0;
        rowsize = grid.size();
        colsize = grid[0].size();
        for(int i=0; i<colsize; i++){
            DFS(grid, 0, i);
            DFS(grid, rowsize-1, i);
        }
        for(int i=0; i<rowsize; i++){
            DFS(grid, i, 0);
            DFS(grid, i, colsize-1);
        }
        // grid[][]: 2->visited
        for(int i=0; i<rowsize; i++){
            for(int j=0; j<colsize; j++){
                if(grid[i][j] == 1)
                    ret++;
            }
        }
        return ret;
    }

    void DFS(vector<vector<int>>& grid, int i, int j){
        static const int directions[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
        if(i>=rowsize || i<0 || j>=colsize || j<0)
            return;
        if(grid[i][j] != 1)
            return;
        
        grid[i][j] = 2;
        for(auto& dir:directions){
            DFS(grid, i+dir[0], j+dir[1]);
        }
    }
};
