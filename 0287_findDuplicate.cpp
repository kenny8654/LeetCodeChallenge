/**
Runtime: 125 ms, Beats: 91.4%
Memory: 61.2 MB, Beats: 92.7%
**/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Floyd Cycle Detection Algorithm
        int tortoise = nums[0];
        int hare  = nums[0];

        do{
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }while(tortoise != hare);

        tortoise = nums[0];
        while(tortoise != hare){
            tortoise = nums[tortoise];
            hare  = nums[hare];
        } 

        return tortoise;
    }
};
