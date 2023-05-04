/**
Runtime: 23 ms, Beats: 44.70%
Memory: 19.5 MB, Beats: 28.90%
**/
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size() < 3)
            return 0;

        int ret = 0;
        vector<int> dp_up(arr.size(), 0); 
        vector<int> dp_down(arr.size(), 0);
        
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i+1] > arr[i])
                dp_up[i+1] = dp_up[i] + 1;
        }
        for(int i=arr.size()-1; i>0; i--){
            if(arr[i-1] > arr[i])
                dp_down[i-1] = dp_down[i] + 1; 
        }
        for(int i=0; i<arr.size(); i++){
            if(dp_up[i] > 0 && dp_down[i] > 0)
                ret = max(ret, dp_up[i]+dp_down[i]);
        }
        return (ret==0)? 0: ret+1;
    }
};
