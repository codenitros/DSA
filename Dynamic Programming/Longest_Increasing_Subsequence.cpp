//https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459


int recurse(int idx, int prev, int arr[], int n, vector<vector<int>>& dp){
	if(idx>=n)return 0;
	
	if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];
	
	int notPick = recurse(idx+1, prev, arr, n, dp);
	int pick=-1e8;
	if(prev==-1 || arr[idx]>arr[prev])pick = 1 + recurse(idx+1, idx, arr, n, dp);
	
	return dp[idx][prev+1]=max(notPick, pick);
	
}

int longestIncreasingSubsequence(int arr[], int n)
{
	vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return recurse(0, -1, arr, n, dp);
}

	