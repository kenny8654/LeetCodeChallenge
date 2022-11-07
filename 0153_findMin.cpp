/**
Runtime: 4 ms, Beats: 77.96%
Memory: 10.2 MB, Beats: 71.16%
**/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int mid= (l+r)/2;
        if(nums[l] <= nums[mid] && nums[mid] <= nums[r]) return nums[l];
        
        while(l<r){
            mid = (l+r)/2;
            if(nums[mid]>nums[mid+1]) return nums[mid+1];
            if(nums[mid] < nums[l]){
                r = mid;
            }else{
                l = mid;
            }
        }
        return nums[mid];
    }
};
