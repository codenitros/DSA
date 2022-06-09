//https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<int, vector<int>, greater<int> > pQ;
        for(int i=0;i<n;i++){
            pQ.push(arr[i]);
        }
        long long ans=0;
        while(pQ.size()>1){
            long long one = pQ.top();
            pQ.pop();
            long long two = pQ.top();
            pQ.pop();
            pQ.push(one+two);
            ans+=one+two;
        }
        return ans;
    }
};