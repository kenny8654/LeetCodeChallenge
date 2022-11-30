/**
Runtime: 22 ms, Beats: 91.17%
Memory: 17.8 MB, Beats: 14.35%
**/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int l = 0;
        int r = (sorted.size() / 2) + (sorted.size() % 2);
        for(int i=nums.size()-1; i>=0; i--){
            if(i%2 == 0){
                nums[i] = sorted[l];
                l++;
            }else{
                nums[i] = sorted[r];
                r++;
            }
        }
    }
};
