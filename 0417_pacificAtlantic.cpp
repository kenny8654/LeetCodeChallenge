/**
Runtime: 51 ms, Beats: 88.83%
Memory: 17.5 MB, Beats: 87.68%
**/
class Solution {
public:
    int row, col;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();
        vector<vector<int>> ret;
        vector<vector<bool>> vTopLeft(row, vector<bool>(col, false)); 
        vector<vector<bool>> vBottomRight(row, vector<bool>(col, false)); 

       for(int i=0; i<row; i++){
           DFS(heights, vTopLeft, i, 0);
           DFS(heights, vBottomRight, i, col-1);
       }
       for(int j=0; j<col; j++){
           DFS(heights, vTopLeft, 0, j);
           DFS(heights, vBottomRight, row-1, j);
       }

       for(int i=0; i<row; i++){
           for(int j=0; j<col; j++){
               if(vTopLeft[i][j] && vBottomRight[i][j])
                    ret.push_back({i,j});
           }
       }
        return ret;
    }

    void DFS(vector<vector<int>>& heights, vector<vector<bool>>& vec, int i, int j){
        if(vec[i][j]) return;
        
        vec[i][j] = true;
        if(i>0 && heights[i][j] <= heights[i-1][j]) DFS(heights, vec, i-1, j);
        if(i<row-1 && heights[i][j] <= heights[i+1][j]) DFS(heights, vec, i+1, j);
        if(j>0 && heights[i][j] <= heights[i][j-1]) DFS(heights, vec, i, j-1);
        if(j<col-1 && heights[i][j] <= heights[i][j+1]) DFS(heights, vec, i, j+1);
        return;
    }
};
