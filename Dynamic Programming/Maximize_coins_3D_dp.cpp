// https://www.codingninjas.com/codestudio/contests/codestudio-weekend-contest-12/problems/15405

/*
One day, Ninja came across a grid of size ‘N’ x ‘M’, where some cells have some gold coins, 
and other cells are empty. Currently, he is at the cell (0, 0) and will go to the (‘N’ - 1, ‘M’ - 1), 
and can go only toward the right or down, i.e., from the cell (i, j), he can go to the (i + 1, j) 
and (i, j + 1) if the cells exist. Now he will collect the gold coins from the cells he is visiting,
 but there is a condition - he can collect coins from at most ‘K’ number of cells from each row. 
 Your task is to find the maximum number of coins Ninja can collect if he chooses his path optimally.
*/





#include<bits/stdc++.h>
int recurse(int i, int j, int limit, int k, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    // base case
    if(i==0 && j==0){
        if(limit > 0)return grid[0][0];
        return 0;
    }
    
    if(i<0 || j<0)return INT_MIN;
    
    if(dp[i][j][limit]!=-1)return dp[i][j][limit];
    
    int ans=INT_MIN;
    if(limit > 0){
        ans = max(ans, grid[i][j] + recurse(i-1, j, k, k, grid, dp));
        ans = max(ans, grid[i][j] + recurse(i, j-1, limit-1, k, grid, dp));
    }
    
    ans = max(ans, recurse(i-1, j, k ,k, grid, dp));
    ans = max(ans, recurse(i, j-1, limit, k, grid, dp));
    return dp[i][j][limit]=ans;
}

int maximumCoins(int n, int m, int k, vector<vector<int>> &grid){
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, 0)));
    for(int limit=1;limit<=k;limit++){
        dp[0][0][limit] = grid[0][0];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int limit=0;limit<=k;limit++){
                	if(i==0 && j==0)continue;
                    int ans=INT_MIN;
                    if(limit > 0){
                        if(i-1 >=0 )ans = max(ans, grid[i][j] + dp[i-1][j][k]);
                        if(j-1>=0) ans = max(ans, grid[i][j] + dp[i][j-1][limit-1]);
                    }

                    if(i-1 >= 0) ans = max(ans, dp[i-1][j][k]);
                    if(j-1 >= 0) ans = max(ans, dp[i][j-1][limit]);
                    dp[i][j][limit]=ans;
            }
        }
    }
    
    return dp[n-1][m-1][k];
}