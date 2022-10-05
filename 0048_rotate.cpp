/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate Image.
Memory Usage: 7.2 MB, less than 33.26% of C++ online submissions for Rotate Image.
**/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        tranpose(matrix);
        flip(matrix);
    }
    
    void tranpose(vector<vector<int>>& matrix){
        for(int i=0; i<matrix.size(); i++){
            for(int j=i+1; j<matrix.size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    void flip(vector<vector<int>>& matrix){
        int left, right;
        if(matrix.size()%2 == 0) {left=matrix.size()/2-1; right=matrix.size()/2;}
        else {left=matrix.size()/2-1, right=matrix.size()/2+1;}
        cout<<left<<" "<<right<<endl;
        while(left >= 0){
            for(int i=0; i<matrix.size(); i++){
                swap(matrix[i][left], matrix[i][right]);
            }
            right++;
            left--;
        }
    }
    
    void swap(int& a, int& b){
        a = a + b;
        b = a - b;
        a = a - b;
    }
};
