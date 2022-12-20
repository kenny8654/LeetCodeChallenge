
/**Runtime: 181 ms, Beats: 95.2%
Memory: 10.8 MB, Beats: 26.49%
**/
#define MAXN 5000001
class Solution {
public:
    int countPrimes(int n) {
        static bool isReady = false;
        static bool isPrime[MAXN];
        if(!isReady){
            memset(isPrime, true, MAXN*sizeof(bool));

            for(int i=2; i*i<n; i++){
                if(isPrime[i]){
                    for(int j=2; i*j<n; j++)
                        isPrime[i*j] = false;
                }
            }
        }
        int ret = 0;
        for(int i=2; i<n; i++){
            ret += isPrime[i];
        }
        return ret;
    }
};
