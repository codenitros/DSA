//https://www.codingninjas.com/codestudio/problems/subsequence-counting_3755256

int mod=1000000007;
int f(int i, int j, string &t, string &s, vector<vector<int>>& dp){
    if(j<0)return 1;// we were able to get 1 occurence after exhausting s
    if(i<0)return 0;// string t is exhausted and nothing to compare
    
    if(dp[i][j]!=-1)return dp[i][j];
    
    if(t[i]==s[j]){
        // two options - pick the occurence or skip this occurence
        return dp[i][j]=( f(i-1, j, t, s, dp) + f(i-1, j-1, t, s, dp))%mod;
    }
    else{
        return dp[i][j]=f(i-1, j, t, s, dp)%mod;
    }
}

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    //vector<vector<int>> dp(lt, vector<int>(ls, -1));
    //return f(lt-1, ls-1, t, s, dp)%mod;
    int m=ls, n=lt;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0;i<=n;i++)dp[i][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(t[i-1]==s[j-1]){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
            }
            else{
                dp[i][j] = dp[i-1][j]%mod;  
            }

        }
    }
    return dp[n][m]%mod;
} 