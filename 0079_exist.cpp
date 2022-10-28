/**
Runtime: 250 ms, faster than 95.25% of C++ online submissions for Word Search.
Memory Usage: 7.9 MB, less than 94.29% of C++ online submissions for Word Search.
**/
class Solution {
public:
    int rowSize, colSize, wordSize;
    bool exist(vector<vector<char>>& board, string word) {
        rowSize = board.size();
        colSize = board[0].size();
        wordSize = word.size();
        
        for(int i=0; i<rowSize; i++)
            for(int j=0; j<colSize; j++)
                if(checkWord(board, word, 0, i, j))
                    return true;
        return false;
    }

    bool checkWord(vector<vector<char>>& board, string& word, int idx, int row, int col){
        if(row<0 || row>=rowSize || col<0 || col>=colSize) return false;
        
        if(board[row][col] == word[idx]){
            if(idx == wordSize-1) return true;
            int lastChar = board[row][col];
            board[row][col] = '*';
            if(checkWord(board, word, idx+1, row+1, col)) return true;
            if(checkWord(board, word, idx+1, row-1, col)) return true;
            if(checkWord(board, word, idx+1, row, col+1)) return true;
            if(checkWord(board, word, idx+1, row, col-1)) return true;
            board[row][col] = lastChar;
            return false;
        }
        return false;
    }
};
