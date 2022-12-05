/**
Runtime: 16 ms, Beats: 98.9%
Memory: 18 MB, Beats: 68.85%
**/
#define SIZE 9
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rowBoard[10][10] = {0};
        bool colBoard[10][10] = {0};
        bool blkBoard[10][10] = {0};

        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                if(board[i][j] == '.') continue;
                
                int num = (int)board[i][j] - '0';
                int blk = i/3*3 + j/3;
                if(rowBoard[i][num] || colBoard[j][num] || blkBoard[blk][num])
                    return false;
                rowBoard[i][num] = colBoard[j][num] = blkBoard[blk][num] = true;
            }
        }
        return true;
    }
};
