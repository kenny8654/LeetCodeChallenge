/**
Runtime: 11 ms, Beats: 95.65%
Memory: 10 MB, Beats: 66.95%
**/
class Solution {
public:
    int rowSize;
    int colSize;
    void solve(vector<vector<char>>& board) {
        rowSize = board.size();
        colSize = board[0].size();
        
        for(int j=0; j<colSize; j++){
            DFS(board, 0, j);
            DFS(board, rowSize-1, j);
        }
        for(int i=1; i<rowSize-1; i++){
            DFS(board, i, 0);
            DFS(board, i, colSize-1);
        }

        for(int i=0; i<rowSize; i++){
            for(int j=0; j<colSize; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '@')
                    board[i][j] = 'O';
            }
        }
    }

    void DFS(vector<vector<char>>& board, int row, int col){
        if(board[row][col] == 'X' || board[row][col] == '@')
            return;
        if(board[row][col] == 'O'){
            board[row][col] = '@';
            if(row>0)         DFS(board, row-1, col);
            if(row+1<rowSize) DFS(board, row+1, col);
            if(col>0)         DFS(board, row, col-1);
            if(col+1<colSize) DFS(board, row, col+1);
        }
    }
};
