// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

#include<bits/stdc++.h>
int frogRecurse(vector<int> &dp, int n, vector<int> &heights){
    if(n==0)return 0;
	
    if(dp[n]!=-1)return dp[n];
    int left = frogRecurse(dp, n-1, heights) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    if(n>1){
        right = frogRecurse(dp, n-2, heights) + abs(heights[n] - heights[n-2]);
    }
	return dp[n] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return frogRecurse(dp, n-1, heights);
}