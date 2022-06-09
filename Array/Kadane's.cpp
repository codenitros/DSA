//https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane's algo
        
        //this solution will also keep track of start and end of index of max sub array
        int max_so_far = INT_MIN;
        int max_end_here = 0;
        // [-2,1,-3,4,-1,2,1,-5,4]
        
        int start_i=0,end_i=0;
        for(int i=0;i<nums.size();i++)
        {
            max_end_here+=nums[i];
            if(max_so_far < max_end_here)
            {
                max_so_far = max_end_here;
                end_i++;
            }
            if(max_end_here < 0)
            {
                max_end_here=0;
                start_i=i+1;
                end_i=i+1;
            }
        }
        return max_so_far;
    }
};