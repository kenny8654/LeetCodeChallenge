/**
Runtime: 4 ms, faster than 75.53% of C++ online submissions for Search in Rotated Sorted Array.
Memory Usage: 10.9 MB, less than 95.65% of C++ online submissions for Search in Rotated Sorted Array.
**/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left=0, right=nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid] == target) return mid;
            if(nums[left]<=nums[mid]){
                if(nums[left]<=target && target<=nums[mid]) right = mid-1;
                else left = mid+1;
            }else{
                if(nums[right]>=target && target>=nums[mid]) left = mid+1;
                else right = mid-1;
            }
        }
        return -1;
    }  
};
