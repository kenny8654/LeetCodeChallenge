/**
Runtime: 41 ms, faster than 89.05% of C++ online submissions for Number of Islands.
Memory Usage: 12.3 MB, less than 85.18% of C++ online submissions for Number of Islands.
**/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ret++;
                }
            }
        }
        return ret;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return;
        else if(grid[i][j] == '0' || grid[i][j] == 'X') return;
        else if(grid[i][j] == '1'){
            grid[i][j] = 'X';
            dfs(grid, i-1, j);
            dfs(grid, i+1, j);
            dfs(grid, i, j-1);
            dfs(grid, i, j+1);
        }
    }
};
