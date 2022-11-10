/**
Runtime: 107 ms, Beats: 80.5%
Memory: 48.5 MB, Beats: 45.91%
**/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farest = 0;
        for(int i=0; i<nums.size(); i++){
            if(farest >= i)
                farest = max(farest, i+nums[i]);
            else
                return false;
        }
        return true;
    }
};
