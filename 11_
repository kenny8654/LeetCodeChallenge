/**
Runtime: 109 ms, faster than 84.24% of C++ online submissions for Container With Most Water.
Memory Usage: 59 MB, less than 80.21% of C++ online submissions for Container With Most Water.
**/
class Solution {
public:
    int maxArea(vector<int>& height) {
      int ret = 0, curr_height = 0;
      int i = 0, j = height.size()-1;
      
      while(i<j){
        if(height[i] > curr_height || height[j] > curr_height){
          curr_height = min(height[i],height[j]);
          ret = max(ret, curr_height*(j-i));
        }
        if(height[i]<height[j])
          i++;
        else
          j--;
      }
      return ret;
    }
};
