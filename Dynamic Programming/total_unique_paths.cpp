// https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470

int getPaths(int row, int col, vector<vector<int>>& dp){
    if(row==0 && col==0)return 1;
    if(row<0 || col<0 )return 0;
    
    if(dp[row][col]!=-1)return dp[row][col];
    return dp[row][col] = getPaths(row-1, col, dp) + getPaths(row, col-1, dp);
}

int uniquePaths(int m, int n) {
	// total paths to [m-1][n-1] = paths to [m-2][n-1] + paths to [m-1][n-2]
    // recurse this
    
    // TC- O(m*n) which are number of states
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return getPaths(m-1, n-1, dp);
}