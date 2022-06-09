// https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029

int recurse(int idx, vector<int>& weight, vector<int>& value, int maxWeight, vector<vector<int>>& dp){
    if(idx==0){
		if(weight[0]<=maxWeight){
            // we can pick same element multiple times 
            return ((int)(maxWeight/weight[idx]) * value[idx]); 
        }else{
            return 0;
        }
    }
    
    if(dp[idx][maxWeight]!=-1)return dp[idx][maxWeight];
    
    int notPick = recurse(idx-1, weight, value, maxWeight, dp);
    int pick=-1e8;
    if(weight[idx]<=maxWeight) pick = value[idx] + recurse(idx, weight, value, maxWeight-weight[idx], dp);
	return dp[idx][maxWeight] = max(pick, notPick);

}

int unboundedKnapsack(int n, int maxWeight, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
    return recurse(n-1, weight, profit, maxWeight, dp);
}
