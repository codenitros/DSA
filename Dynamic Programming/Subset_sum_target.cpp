// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

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
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // pick not pick
    // both idx and target is changing 
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return f(n-1, k, arr, dp);
}