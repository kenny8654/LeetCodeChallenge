/**
Runtime: 0 ms, Beats: 100%
Memory: 8.1 MB, Beats: 91.21%
**/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int i = 0;

        while(i<=right){
            if(nums[i] == 0){
                swap(nums[left], nums[i]);
                left++;
                i++;
            }else if(nums[i] == 1){
                i++;
            }else if(nums[i] == 2){
                swap(nums[right], nums[i]);
                right--;
            }
        }
    }
};
