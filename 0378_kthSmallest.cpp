/**
Runtime: 32 ms, Beats: 94.52%
Memory: 13.1 MB, Beats: 93.85%
**/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];

        while(low < high){
            int cnt = 0;
            int mid = low + (high-low)/2;
            for(int i=0; i<n; i++){
                auto it = upper_bound(matrix[i].begin(), matrix[i].end(), mid);
                cnt += it - matrix[i].begin();
            }

            if(cnt < k) 
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
