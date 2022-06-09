// https://leetcode.com/problems/decode-ways/

int driver(int idx, string str, int n , vector<int>& dp){
	// base case
	if(idx>=n)return 1;
	if(idx<n && str[idx]=='0')return 0;
	
	if(dp[idx]!=-1)return dp[idx];
	
	int ways = 0;
	
	// single digit
	if(str[idx]!='0')ways = driver(idx+1, str, n, dp);
	
	// 2 digit 
	if(idx+1 < n && ((str[idx]=='1' && str[idx+1]<='9') 
					 || (str[idx]=='2' && str[idx+1]<='6')))
	{
		ways+=driver(idx+2, str, n, dp);
	}
	
	return dp[idx]=(ways)%(1000000007);
}
int numDecodings(string str) {
    // add your logic here
	int n=str.length();
	vector<int> dp(n, -1);
	return driver(0, str, n, dp);
}