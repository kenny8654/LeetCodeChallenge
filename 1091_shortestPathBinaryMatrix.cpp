/**
Runtime: 81 ms, Beats: 55.51%
Memory: 21.5 MB, Beats: 50.66%
**/
class Solution {
private:
    int row;
    int col;
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return -1;

        row = grid.size();
        col = grid[0].size();
        vector<vector<int>> path(row, vector<int>(col, -1));
        path[0][0] = 1;
        queue<pair<int,int>> que;
        que.push({0,0});
        BFS(grid, path, que);
        return path[row-1][col-1];
    }

    void BFS(vector<vector<int>>& grid, vector<vector<int>>& path, queue<pair<int,int>>& que){
        static const int dirs[8][2] = {{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};

        int que_size = que.size();
        while(que_size-->0){
            int cur_x = que.front().first;
            int cur_y = que.front().second;
            que.pop();
            for(int i=0; i<8; i++){
                int next_x = cur_x + dirs[i][0];
                int next_y = cur_y + dirs[i][1];
                if(next_x == row || next_x == -1 || next_y == col || next_y == -1)
                    continue;;
                if(grid[next_x][next_y] == 1 || path[next_x][next_y] != -1)
                    continue;
                path[next_x][next_y] = path[cur_x][cur_y] + 1;
                que.push({next_x, next_y});
                if(next_x == row-1 && next_y == col-1)
                    return;
            }
        }
        if(que.size())
            BFS(grid, path, que);
    }
};
