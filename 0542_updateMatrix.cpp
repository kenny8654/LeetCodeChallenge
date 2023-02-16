/**
Runtime: 87 ms, Beats: 72.50%
Memory: 30.2 MB, Beats: 68.89%
**/
class Solution {
private:
    int rowSize;
    int colSize;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        rowSize = mat.size();
        colSize = mat[0].size();
        vector<vector<int>> ret(rowSize, vector<int>(colSize, -1));
        queue<pair<int, int>> que;

        for(int i=0; i<rowSize; i++){
            for(int j=0; j<colSize; j++){
                if(mat[i][j] == 0){
                    ret[i][j] = 0;
                    que.push({i, j});
                }
            }
        }

        while(!que.empty()){
            BFS(ret, que.front().first, que.front().second, que);
            que.pop();
        }
        return ret;
    }

    void BFS(vector<vector<int>>& ret, int row, int col, queue<pair<int, int>>& que){
        static const int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        for(int i=0; i<4; i++){
            int new_row = row+dir[i][0];
            int new_col = col+dir[i][1];
            if(new_row>=0 && new_row<rowSize && new_col>=0 && new_col<colSize){
                if(ret[new_row][new_col] == -1){
                    ret[new_row][new_col] = ret[row][col] + 1;
                    que.push({new_row, new_col});
                }
            }
        }
    }
};
