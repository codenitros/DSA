// https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628

int mod = 1e9+7;
int f(int idx, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(idx==0) {
        if(target == 0 && arr[idx]==0)return 2;
        if(target == 0 || target == arr[0]) return 1;
        return 0;
    }
    
    if(dp[idx][target]!=-1)return dp[idx][target];
    
    int pick=0;
    if(arr[idx] <= target) pick = f(idx-1, target-arr[idx], arr, dp);
    int notPick = f(idx-1, target, arr, dp);
    
    return dp[idx][target] = (pick + notPick)%mod;
}

int findWays(vector<int> &num, int tar)
{
    int n=num.size();
	vector<vector<int>> dp(n, vector<int>(tar+1, -1));
	return f(n-1, tar, num, dp);
}

int countPartitions(int n, int d, vector<int> &arr) {
    // S1 - S2 = D
    // totSum - S1 - S2 = D
    // totSum - 2S2 = D
    // S2 = (totSum - D)/2
    
    // find count of subset with given target
    // target is  S2 = (totSum - D)/2
    // ------------
    // Base cases
    // (totSum-D) >=0  and (totSum-D) is even 
    int totSum=0;
    for(int i=0;i<n;i++)totSum+=arr[i];
    if((totSum - d) < 0 || (totSum-d)%2)return false;
    
    return findWays(arr, (totSum-d)/2);
}


