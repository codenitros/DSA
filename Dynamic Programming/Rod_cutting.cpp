//

int recurse(int idx, int N, vector<int>& price, vector<vector<int>>& dp){
    if(idx==0){
		return N*price[0];
    }
    
    if(dp[idx][N]!=-1)return dp[idx][N];
    
    int notPick = recurse(idx-1, N, price, dp);
    int pick=-1e8;
    int rodLength=idx+1; // 1 based indexing
    if(rodLength <= N) pick = price[idx] + recurse(idx, N - rodLength, price, dp);
	return dp[idx][N] = max(pick, notPick);

}
int cutRod(vector<int> &price, int n)
{
	// knapsack 
    // 1 based indexing
   	vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return recurse(n-1, n, price, dp);
}


// Tabulation
int cutRod(vector<int> &price, int n)
{
	// knapsack 
  // 1 based indexing
  vector<vector<int>> dp(n, vector<int>(n+1, 0));

	for(int N=0;N<=n;N++){
		dp[0][N] = N * price[0];
	}
	
	for(int idx=1;idx<n;idx++){
		for(int N=0;N<=n; N++){
			int notPick = dp[idx-1][N];
			int pick=-1e8;
			int rodLength=idx+1; // 1 based indexing
			if(rodLength <= N) pick = price[idx] + dp[idx][N - rodLength];
			dp[idx][N] = max(pick, notPick);
		}
	}
	
	return dp[n-1][n];
}


