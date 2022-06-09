// https://leetcode.com/problems/maximal-square/


class Solution {
public:
    
    int driver(int i, int j, vector<vector<char>>& matrix, int& ans, vector<vector<int>>& dp){
        // base case
        if(i<0 || j<0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        int up=driver(i-1,j,matrix, ans, dp);
        int left=driver(i, j-1, matrix, ans, dp);
        int diag=driver(i-1, j-1, matrix, ans, dp);
        if(matrix[i][j]=='1'){
            int a = 1 + min(left, min(up, diag));
            ans=max(ans, a);
            return dp[i][j] = a;
        }else{
            return dp[i][j] = 0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        driver(n-1, m-1, matrix, ans, dp);
        
        return ans*ans;
    }
};