/**
Runtime: 6 ms, Beats: 92.75%
Memory: 6.4 MB, Beats: 84.83%
**/
#define MAXN 10001 
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp{0};
        static vector<int> squares;

        if(squares.empty()){
            for(int i=1; (i*i)<MAXN; i++){
                squares.push_back(i*i);
            }

            dp[0] = 0;
            for(int i=1; i<MAXN; i++){
                int tmp = INT_MAX;
                for(int num:squares){
                    if(num > i)
                        break;
                    tmp = (i-num >= 0)? min(dp[i-num]+1, tmp): tmp;
                }
                dp.emplace_back(tmp);
            }
        }
        return dp[n];
    }
};
