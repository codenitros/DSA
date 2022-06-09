// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

#include<bits/stdc++.h>
int f(vector<int>& dp, int idx, vector<int> &nums){
    if(idx==0)return nums[0];
    if(idx<0)return 0;
    if(dp[idx]!=-1)return dp[idx];
    int pick = nums[idx] + f(dp, idx-2, nums);
    int notPick = f(dp, idx-1, nums);
    
    return dp[idx] = max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
   	// pick or not pick
    int n=nums.size();
    vector<int> dp(n+1, -1);
    return f(dp,n-1, nums);
}