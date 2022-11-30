/**
Runtime: 0 ms, Beats: 100%
Memory: 7 MB, Beats: 60.47%
**/
class Solution {
public:
    int rowSize, colSize;
    void gameOfLife(vector<vector<int>>& board) {
        rowSize = board.size(); 
        colSize = board[0].size();
        vector<int> tmp(colSize, 0);
        
        for(int i=0; i<rowSize; i++){
            for(int j=0; j<colSize; j++){
                int cnt = neighbors(board, i, j);
                cout<<i<<","<<j<<":"<<cnt<<endl;
                if(board[i][j] == 0 && cnt == 3)
                    board[i][j] = 2; // curr:0, next:1
                else if(board[i][j] == 1 && (cnt < 2 || cnt > 3)){
                    board[i][j] = 3; // curr:1, next:0
                }
            }
        }

        for(int i=0 ; i<rowSize; i++){
            for(int j=0; j<colSize; j++){
                board[i][j] = (board[i][j]==2)? 1: (board[i][j]==3)? 0 : board[i][j];
            }
        }
        return;
    }

    int neighbors(vector<vector<int>>& board, int row, int col){
        int cnt = 0;
        if(row > 0){
            if(col > 0 && board[row-1][col-1]%2) cnt++;
            if(board[row-1][col]%2) cnt++;
            if(col < colSize-1 && board[row-1][col+1]%2) cnt++;
        }
        if(col < colSize-1 && board[row][col+1]%2) cnt++;
        if(row < rowSize-1){
            if(col < colSize-1 && board[row+1][col+1]%2) cnt++;
            if(board[row+1][col]%2) cnt++;
            if(col > 0 && board[row+1][col-1]%2) cnt++;
        }
        if(col > 0 && board[row][col-1]%2) cnt++;
        return cnt;
    }
};
