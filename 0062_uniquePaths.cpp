/**
Runtime: 0 ms, Beats: 100%
Memory: 6 MB, Beats: 79.61%
**/
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ret = 1;

        for(int i=1; i<n; i++){
            ret = ret * (m+i-1) / (i);
        }
        return (int) ret;
    }
};
