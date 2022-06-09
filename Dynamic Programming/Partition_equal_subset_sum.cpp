// https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980


// Intuition
// 1. to divide equally total sum should be even number
// 2. if we can find subset with sum == totalSum/2 then we can achive the required 


// same as subset sum only target has been changed
bool f(int n, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0)return true;
    if(n==0)return arr[0]==target;
    
    if(dp[n][target]!=-1)return dp[n][target];
    
    bool pick=false;
    if(arr[n] <= target) pick = f(n-1, target-arr[n], arr, dp);
    bool notPick = f(n-1, target, arr, dp);
    
    // automatic convertion to boolean
    return dp[n][target] = (pick || notPick);
}

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    int totalSum=0;
    for(int i=0;i<n;i++)totalSum+=arr[i];
    if(totalSum%2)return false;
    int k = totalSum/2;
    
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return f(n-1, k, arr, dp);
}
