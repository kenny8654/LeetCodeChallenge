/**
Runtime: 0 ms, Beats: 100%
Memory: 6.8 MB, Beats: 92.13%
**/
class Solution {
private:
    int rowSize, colSize;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        rowSize = matrix.size();
        colSize = matrix[0].size();

        for(int i=0; i<(rowSize/2+rowSize%2) && i<(colSize/2+colSize%2) ; i++){
            spiral(matrix, ret, i);
        }
        return ret;
    }

    void spiral(vector<vector<int>>& matrix, vector<int>& ret, int i){
        int row = i, col = i;
        for(; col<colSize-i; col++){
            ret.push_back(matrix[row][col]);
        }
        col--; row++;
        for(; row<rowSize-i; row++){
            ret.push_back(matrix[row][col]);
        }
        row--; col--;
        for(; col>i && row>i; col--){
            ret.push_back(matrix[row][col]);
        }
        for(; row>i && col>=i; row--){
            ret.push_back(matrix[row][col]);
        }
    }
};
