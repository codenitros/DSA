// https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349


#include<bits/stdc++.h>
int minPathSum(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp)
{
    if(row==0 && col==0)return grid[row][col];
    if(row<0 || col<0)return INT_MAX;
    
    if(dp[row][col]!=-1)return dp[row][col];
    
    int up = minPathSum(row-1, col, grid, dp);
    int left = minPathSum(row, col-1, grid, dp);
    
    return dp[row][col] = grid[row][col] + min(left, up);
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size(), m=grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return minPathSum(n-1, m-1, grid, dp);
}


//  Tabulation

int minPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    
    vector<vector<int>> dp(n, vector<int>(m,0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){ 
            if(i==0 && j==0)dp[i][j]=grid[i][j];
            else {
                int up = grid[i][j];
                if(i>0)up+= dp[i-1][j]; // add the prev dp state
                else up = INT_MAX; // no path

                int left = grid[i][j];
                if(j>0)left+= dp[i][j-1]; // add the prev dp state
                else left = INT_MAX; // no path

                dp[i][j] = min(up, left);                   
            }

        }
    }
    
    return dp[n-1][m-1];
}