/**
Runtime: 35 ms, Beats: 85.23%
Memory: 25.1 MB, Beats: 57.35%
**/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
