// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

int f(int idx, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(idx==0) {
        if(target == 0 && arr[idx]==0)return 2; // 2 ways since including and not including 
        if(target == 0 || target == arr[0]) return 1; // one way 
        return 0;
    }
    
    if(dp[idx][target]!=-1)return dp[idx][target];
    
    int pick=0;
    if(arr[idx] <= target) pick = f(idx-1, target-arr[idx], arr, dp);
    int notPick = f(idx-1, target, arr, dp);
    
    // automatic convertion to boolean
    // everything same as subset sum equak to k except we are adding the results 
    // of every function call
    return dp[idx][target] = (pick + notPick);
}

int findWays(vector<int> &num, int tar)
{
    int n=num.size();
	vector<vector<int>> dp(n, vector<int>(tar+1, -1));
	return f(n-1, tar, num, dp);
}