// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int driver(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp){
        // base case
        if(i<0 || j<0 || mat[i][j]==0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(mat[i][j]==1){
            return dp[i][j] = 1 + min(driver(i-1, j, mat, dp),
                        min(driver(i, j-1, mat, dp), driver(i-1, j-1, mat, dp)));
        }else{
            return dp[i][j] = 0;
        }
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int ans=0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int p=n-1; p>=0;p--){
            for(int q=m-1; q>=0;q--){
                ans+=driver(p, q, matrix, dp);
            }
        }
        return ans;
    }
};