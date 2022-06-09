// https://www.codingninjas.com/codestudio/problems/target-sum_4127362


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
    
    // automatic convertion to boolean
    // everyhing same as subset sum equak to k except we are adding the results 
    // of every function call
    return dp[idx][target] = (pick + notPick);
}

int findWays(vector<int> &num, int tar)
{
    int n=num.size();
	vector<vector<int>> dp(n, vector<int>(tar+1, -1));
	return f(n-1, tar, num, dp);
}

int countPartitions(int n, int d, vector<int> &arr) { 
    int totSum=0;
    for(int i=0;i<n;i++)totSum+=arr[i];
    if((totSum - d) < 0 || (totSum-d)%2)return false;
    
    return findWays(arr, (totSum-d)/2);
}
int targetSum(int n, int target, vector<int>& arr) {
    // here all negative can be one subset and all positive another subset
    // question boils down to find number of such partition with given target as difference
    // using same code as - Partition with given difference
    countPartitions(n, target, arr);
}
