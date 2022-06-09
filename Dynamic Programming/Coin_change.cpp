// https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471

#include<bits/stdc++.h>
long recurse(int idx, int *num, int target, vector<vector<long>>& dp){
    if(idx==0){
        if(target%num[idx]==0)return 1; 
        else return 0;
    }
    
    if(dp[idx][target]!=-1)return dp[idx][target];
    
    long notPick=recurse(idx-1, num, target, dp);
    long pick = 0;
    // idx remains same since we can pick same ele multiple times
    if(num[idx]<=target) pick = recurse(idx, num, target-num[idx], dp);
	
    return dp[idx][target] = notPick + pick;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1, -1));
    return recurse(n-1, denominations, value, dp);
}


// tabulation
int numberOfCombinations(vector<int> &coins, int target) {
    int n=coins.size();
	vector<vector<int>> dp(n, vector<int>(target+1, 0));
	
	for(int t=0;t<=target;t++){
		if(t%coins[0]==0)dp[0][t]=1;
		else dp[0][t]=0;
	}
	
	for(int i=1;i<n;i++){
		for(int t=0;t<=target;t++){
			int notPick = dp[i-1][t];
			int pick = 0;
			if(coins[i]<=t)pick = dp[i][t - coins[i]];
			dp[i][t] = notPick + pick;
		}
	}
	
	
	return dp[n-1][target];
}