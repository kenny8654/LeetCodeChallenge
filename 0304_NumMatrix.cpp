/**
Runtime: 401 ms, Beats: 91.73%
Memory: 144.7 MB, Beats: 16.1
**/
class NumMatrix {
private:
    int rowSize;
    int colSize;
    vector<vector<long>> mVec;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        rowSize = matrix.size();
        colSize= matrix[0].size();
        mVec.resize(rowSize, vector<long>(colSize));
        
        for(int i=rowSize-1; i>=0; i--){
            for(int j=colSize-1; j>=0; j--){
                mVec[i][j] = fillVec(matrix, i, j);
            }
        }
    }
    
    long fillVec(vector<vector<int>>& matrix, int row, int col){
        return matrix[row][col]
            + ((row+1==rowSize)? 0: mVec[row+1][col])
            + ((col+1==colSize)? 0: mVec[row][col+1])
            - (((row+1==rowSize) || (col+1==colSize))? 0: mVec[row+1][col+1]);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return mVec[row1][col1]
            - ((col2+1==colSize)? 0: mVec[row1][col2+1])
            - ((row2+1==rowSize)? 0: mVec[row2+1][col1])
            + (((row2+1==rowSize) || (col2+1==colSize))? 0: mVec[row2+1][col2+1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
