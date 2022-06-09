// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998

// max path sum from any cell in first row to any cell in last row
// 3 moves allowed
// down , left diagonal, right diagonal

#include<bits/stdc++.h>
int getPath(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp){
    if(col<0 || col>=matrix[0].size())return -1e8; // this condition can happen due to diagonal movement

    if(row==matrix.size()-1)return matrix[row][col];// just return value at that cell
    
    if(dp[row][col]!=-1)return dp[row][col];
    
    int down = matrix[row][col] + getPath(row+1, col, matrix, dp);
    int diagLeft = matrix[row][col] + getPath(row+1, col-1, matrix, dp);
    int diagRight = matrix[row][col] + getPath(row+1, col+1, matrix, dp);
    
    return dp[row][col] = max(down, max(diagLeft, diagRight));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    // following bottom-up (0-->n)
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi=-1e8;
    for(int i=0;i<m;i++){
        maxi=max(maxi, getPath(0, i, matrix, dp));
    }
    return maxi;
}






// Tabulation

int findMaxPath(vector<vector<int>> &mat) {
    int n=mat.size();
	int m=mat[0].size();
	
	vector<vector<int>> dp(n, vector<int>(m, 0));
	
	for(int k=0;k<m;k++)dp[0][k]=mat[0][k];
	
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			int up = mat[i][j] + dp[i-1][j];
			
			int diagLeft = mat[i][j]; 
			if(j-1>=0) diagLeft+= dp[i-1][j-1];
			else diagLeft+= INT_MIN;
			
			int diagRight = mat[i][j];
			if(j+1<m) diagRight+= dp[i-1][j+1];
			else diagRight+=INT_MIN;
			
			dp[i][j] = max(up,max(diagLeft, diagRight));
		}
	}
	
	int maxi=INT_MIN;
	for(int i=0;i<m;i++){
		maxi = max(dp[n-1][i], maxi);
	}
	return maxi; 
}