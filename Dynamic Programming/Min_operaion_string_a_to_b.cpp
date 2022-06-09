// https://www.codingninjas.com/codestudio/problems/can-you-make_4244510

#include<bits/stdc++.h>
string printLongestString(string s, string t, vector<vector<int>>& dp){
    int n=s.length(), m=t.length();
    int length=dp[n][m];
    string ans="";
    int i=n,j=m;
    while(i>0 && j>0){
        if(dp[i-1][j]==dp[i][j-1]){
            ans+=s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }else {
            j--;
        }
    }
   	reverse(ans.begin(), ans.end());
    return ans;
}

int lcs(string s, string t)
{
    //TC- O(n*m)
    //SC - O(n*m) + O(n+m)
	int n=s.size(), m=t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int j=0;j<=m;j++)dp[0][j]=0;
    for(int i=0;i<=n;i++)dp[i][0]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
    }
    
    //cout<<printLongestString(s, t, dp);
    return dp[n][m];
}

int canYouMake(string &str, string &ptr)
{
    int lcsCount=lcs(str, ptr);
    return (str.size()-lcsCount) + (ptr.size()-lcsCount);
}