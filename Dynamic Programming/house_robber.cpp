// https://leetcode.com/problems/house-robber/

// same as Max_non_adj_sum
class Solution {
public:
    int f(vector<int>& dp, int idx, vector<int>& nums){
        if(idx==0)return nums[0];
        if(idx<0)return 0;
        
        if(dp[idx]!=-1)return dp[idx];
        
        int pick = nums[idx] + f(dp, idx-2, nums);
        int notPick = f(dp, idx-1, nums);
        return dp[idx] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1, -1);
        return f(dp, n-1, nums);
    }
};