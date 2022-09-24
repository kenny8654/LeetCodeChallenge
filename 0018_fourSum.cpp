/**
Runtime: 52 ms, faster than 91.30% of C++ online submissions for 4Sum.
Memory Usage: 13.7 MB, less than 26.98% of C++ online submissions for 4Sum.

**/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        if(nums[nums.size()-1]<0 && target>0) return ret;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0 && target<0) break;
            if(i>0 && (nums[i]==nums[i-1])) continue;
            vector<vector<int>> tmp = threeSum(nums, i+1, nums.size()-1, target-nums[i]);
            for(int j=0; j<tmp.size(); j++){
                tmp[j].insert(tmp[j].begin(), nums[i]);
                ret.push_back(tmp[j]);
            }
        }
        return ret;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums, int left, int right, long target) {
        vector<vector<int>> ret;
        if(nums[right]<0 && target>0) return ret;
        for(int i=left; i<right; i++){
            if(nums[i]>0 && target<0) break;
            if(i>left && (nums[i]==nums[i-1])) continue;  
            vector<vector<int>> tmp = twoSum(nums, i+1, right, target-nums[i]);
            for(int j=0; j<tmp.size(); j++){
                tmp[j].insert(tmp[j].begin(), nums[i]);
                ret.push_back(tmp[j]);
            }
        }
        return ret;
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, int left, int right, long target) {
        vector<vector<int>> ret;
        if((nums[left]>0 && target<0) || (nums[right]<0 && target>0)) return ret;
        while(left<right){
            int sum = nums[left]+nums[right];
            if(sum == target){
              ret.push_back({nums[left], nums[right]});
              while(left+1<right && nums[left]==nums[left+1]) left++;
              while(left<right-1 && nums[right]==nums[right-1]) right--;
              left++; right--;
            }
            else if(sum < target) left++;
            else right--;
        }
        return ret;
    }
};
