// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542


int recurse(int idx, vector<int>& weight, vector<int>& value, int maxWeight, vector<vector<int>>& dp){
    if(idx==0){
		if(weight[0]<=maxWeight){//obviously pick it
            return value[idx];
        }else{
            return 0;// not possible to pick
        }
    }
    
    if(dp[idx][maxWeight]!=-1)return dp[idx][maxWeight];
    
    int notPick = recurse(idx-1, weight, value, maxWeight, dp);
    int pick=-1e8;
    if(weight[idx]<=maxWeight) pick = value[idx] + recurse(idx-1, weight, value, maxWeight-weight[idx], dp);
	return dp[idx][maxWeight] = max(pick, notPick);

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    // greedy does not work here --> all combos --> recursion --> dp
	// return max value
    // max val for every possible weight
    
    // TC- O(W * N)
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
    return recurse(n-1, weight, value, maxWeight, dp);
}