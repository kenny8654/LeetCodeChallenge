/**
Runtime: 16 ms, faster than 89.03% of C++ online submissions for Set Matrix Zeroes.
Memory Usage: 13.5 MB, less than 11.88% of C++ online submissions for Set Matrix Zeroes.
**/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> sRow, sCol;
        int R = matrix.size(), C=matrix[0].size();
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(matrix[i][j] == 0){
                    sRow.insert(i);
                    sCol.insert(j);
                }
            }
        }
        for(int r:sRow){
            memset(&matrix[r][0], 0, C*sizeof(int));
        }
        for(int c:sCol)
            for(int i=0; i<R; i++)
                matrix[i][c] = 0;
    }
};
