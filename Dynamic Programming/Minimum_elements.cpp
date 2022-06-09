// https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091


int recurse(int idx, vector<int>& num, int target, vector<vector<int>>& dp){
    if(idx==0){
        if(target%num[idx]==0)return target/num[idx]; 
        else return 1e9; // INT_MAX may cause overflow
    }
    
    if(dp[idx][target]!=-1)return dp[idx][target];
    
    int notPick=recurse(idx-1, num, target, dp);
    int pick = 1e9;
    // idx remains same since we can pick same ele multiple times
    if(num[idx]<=target) pick = 1 + recurse(idx, num, target-num[idx], dp);
	
    return dp[idx][target] = min(notPick, pick);
}

int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>> dp(n, vector<int>(x+1, -1));
    int ans = recurse(n-1, num, x, dp);
   
   	if(ans >= 1e9)return -1;
    return ans;
}