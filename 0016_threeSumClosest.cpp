/**
Runtime: 282 ms, faster than 85.90% of C++ online submissions for 3Sum Closest.
Memory Usage: 16.1 MB, less than 97.71% of C++ online submissions for 3Sum Closest.
**/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int ret = 100000;
      int minDiff = INT_MAX;
      std::sort(nums.begin(), nums.end());

      for(int i=0; i<nums.size()-2; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j=i+1, k=nums.size()-1;
        while(j<k){
          int checkdiff = INT_MAX;
          int sum = nums[j]+nums[k]+nums[i];
          if(sum == target) return target;
          int diff = abs(sum-target);
          if(diff > checkdiff) break;
          if(diff <= minDiff){
            checkdiff = diff;
            minDiff = diff;
            ret = sum;
          }
          if(sum < target) j++;
          else k--;
        }
      }
      return ret;
    }
};