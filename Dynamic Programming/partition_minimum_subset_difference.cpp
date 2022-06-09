// https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494



int minSubsetSumDifference(vector<int>& arr, int n)
{
	// we can derive if every possible target between 1 & totalSum is 
    // possible or not
    
    // intuition is - subset sum problem
    // the tabulation in subset sum
    // last row of tabulation will tell if a target from 0 -> totalSum is possible
    // if a is first subsetSum then totalSum-a is second subset sum
    // we can then find the min difference of all possible subsets in that way
    int totSum=0;
    for(int i=0;i<n;i++)totSum+=arr[i];
	
    vector<vector<bool>> dp(n, vector<bool>(totSum, 0));
    for(int i=0;i<n;i++)dp[i][0]=true; // it is always possible to get target 0 
    if(arr[0] <= totSum)dp[0][arr[0]] = true;
    for(int idx=1;idx<n;idx++){
        for(int target=1; target<=totSum; target++){
            bool notTake = dp[idx-1][target];
            bool take = false;
            if(arr[idx]<=target)take = dp[idx-1][target-arr[idx]];
            dp[idx][target] = take || notTake;
        }
    }
    
    // so just query the last row (n-1) for every target i->0 to total Sum
    int mini=1e9;
    for(int i=0;i<=totSum;i++){
        if(dp[n-1][i]){
            int s1=i;
            int s2=totSum-i;
            mini = min(mini, abs(s1-s2));
        }
    }
    return mini;
}
