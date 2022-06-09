//https://leetcode.com/problems/maximum-sum-circular-subarray/


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
            
        int max_straight_sum=INT_MIN, temp_max_straight_sum=0;
        int min_straight_sum=INT_MAX, temp_min_straight_sum=0;
        int totalSum=0;
        
        for(int i=0;i<n;i++){
            
            // compute maxStraight sum using Kadane's algo
            temp_max_straight_sum+=nums[i];
            max_straight_sum=max(max_straight_sum, temp_max_straight_sum);
            if(temp_max_straight_sum<0)temp_max_straight_sum=0;
            
            
            // compute minStraight sum using modified Kadane's algo
            temp_min_straight_sum+=nums[i];
            min_straight_sum=min(min_straight_sum, temp_min_straight_sum);
            if(temp_min_straight_sum>0)temp_min_straight_sum=0;
            
            
            // normal array sum
            totalSum+=nums[i];
        }
        
        
        if(totalSum == min_straight_sum)return max_straight_sum;// all elements are negative
        return max(max_straight_sum, totalSum-min_straight_sum);
        
    }
};