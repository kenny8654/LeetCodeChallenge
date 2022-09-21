/**
Runtime: 76 ms, faster than 96.63% of C++ online submissions for 3Sum.
Memory Usage: 19.9 MB, less than 85.43% of C++ online submissions for 3Sum.
**/
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ret;
    std::sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size()-2; i++){
      if(nums[i] > 0) break;
      if(i>0 && (nums[i]==nums[i-1])) continue;  
      
      int j=i+1, k=nums.size()-1;
      if(nums[k] < 0) break;
      while(j < k){
        int sum = nums[j]+nums[k]+nums[i];
        if(sum == 0){
          ret.push_back({nums[i], nums[j], nums[k]});
          while(j+1<k && nums[j]==nums[j+1]) j++;
          while(j<k-1 && nums[k]==nums[k-1]) k--;
          j++; k--;
        }
        else if(sum < 0)
          j++;
        else
          k--;
      }
    }
    return ret;
  }
};
