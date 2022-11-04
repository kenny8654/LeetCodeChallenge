/**
Runtime: 3 ms, Beats: 99.2%
Memory: 13.9 MB, Beats: 25.72%
**/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int positive_num=nums[0], negative_num=nums[0], ret=nums[0];

        for(int i=1; i<nums.size(); i++){
            if(nums[i] < 0)
                swap(positive_num, negative_num);

            positive_num = max(nums[i], positive_num*nums[i]);
            negative_num = min(nums[i], negative_num*nums[i]);
            ret = max(ret, positive_num);
        }
        return ret;
    }
};
