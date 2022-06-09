// https://www.codingninjas.com/codestudio/problems/triangle_1229398

#include<bits/stdc++.h>
int getMinPath(vector<vector<int>>& tri, int i, int j, int n, vector<vector<int>>& dp){
    if(i==n-1)return tri[n-1][j];
    
    if(dp[i][j]!=-1)return dp[i][j];
   	int costDown = tri[i][j] + getMinPath(tri, i+1, j, n, dp);
    int costDiag = tri[i][j] + getMinPath(tri, i+1, j+1, n,dp);    
    
    return dp[i][j]=min(costDown, costDiag);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
    // bottom up is prefereble
    vector<vector<int>> dp(n, vector<int>(n, -1));
	return getMinPath(triangle, 0, 0, n, dp);
}