// https://leetcode.com/problems/climbing-stairs/
// 1 or 2 steps allowed

class Solution {
public:
    int fib(int n, vector<int>& dp){
        if(n==0)return 1;
        if(n==1)return 1;
        dp[n] = fib(n-1, dp) + fib(n-2, dp);
        return dp[n];
    }

    int climbStairs(int n){
        vector<int> dp(n+1, 0);
        return fib(n, dp);
    }

    // Tabulation
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    