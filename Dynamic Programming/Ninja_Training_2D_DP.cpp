// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

int f(int idx, vector<vector<int>> &points, int prevTask, vector<vector<int>>& dp){
    // base case just pick the task with maximum that is not prev
    if(idx==0){
        int maxi=0;
        for(int i=0;i<=2;i++){
            if(i!=prevTask){
                maxi=max(maxi, points[idx][i]);
            }
        }
        return maxi;
    }
    if(dp[idx][prevTask]!=-1)return dp[idx][prevTask];
    // pick not pick
    int maxi=0;
    for(int i=0;i<=2;i++){
        if(i!=prevTask){
            int curPoint = points[idx][i] + f(idx-1, points, i, dp);
            maxi=max(maxi, curPoint);
        }
    }
    return dp[idx][prevTask]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Greedy fails --> try all possible ways --> recursion --> dp
    
    // Days are our index
    vector<vector<int>> dp(n,vector<int>(4, -1));
    // 3 means nothing was picked initially  
    return f(n-1, points, 3, dp);
}