/**
Runtime: 6 ms, faster than 94.75% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 13.5 MB, less than 84.66% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
**/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearch(nums, target, -1), binarySearch(nums, target, 1)};
    }
    
    int binarySearch(vector<int>& nums, int target, int status){
        int left = 0, right = nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target){
                if(mid+status>=nums.size() || mid+status<0 || nums[mid+status]!=target) return mid;
                else if(status == -1) right = mid-1;
                else if(status == 1) left = mid+1; 
            } 
            else if(nums[mid]<target) left=mid+1;
            else if(nums[mid]>target) right=mid-1;
        }
        return -1;
    }
};
