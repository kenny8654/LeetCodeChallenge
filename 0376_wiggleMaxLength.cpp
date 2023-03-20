/**
Runtime: 0 ms, Beats: 100%
Memory: 7.2 MB, Beats: 45.11%
**/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int peak(1), bot(1);
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                peak = bot + 1; 
            }
            else if(nums[i] < nums[i-1]){
                bot = peak +1 ;
            }
        }
        return max(peak, bot);
    }
};
