// https://leetcode.com/problems/minimum-size-subarray-sum/



class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0, n=nums.size(), mini=INT_MAX, sum=0;
        while(r<n){
            sum+=nums[r++];// move r until there is a sum >= target
            while(sum>=target){ // try minimizing the window we have 
                mini=min(mini, r-l);
                sum-=nums[l++];
            }
        }
        return mini==INT_MAX?0:mini;
    }
};