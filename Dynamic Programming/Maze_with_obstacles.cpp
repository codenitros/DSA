// https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241


#define mod 10e9
int waysToReach(int row, int col, vector<vector<int>> &mat, vector<vector<int>>& dp){
    if(row==0 && col==0)return 1;
    if(row<0 || col<0 || mat[row][col]==-1)return 0;
   
    if(dp[row][col]!=-1)return dp[row][col];
    
	int left = waysToReach(row-1, col, mat, dp);
    int up = waysToReach(row, col-1, mat, dp);
    
    return (dp[row][col] = (left + up)%1000000007);
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    // TC - O(n*m)
    // SC - O()
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return waysToReach(n-1, m-1, mat, dp);
}
