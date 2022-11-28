/**
Runtime: 111 ms, Beats: 89.49%
Memory: 14.9 MB, Beats: 69.39%
**/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;
        int rowSize = matrix.size();

        while(col >= 0 && row <rowSize){
            if(matrix[row][col] == target)
                return true;
            
            if(matrix[row][col] > target)
                col--;
            else
                row++;
        }
        return false;
    }
};
