//

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	void dfs(int node, vector<int>& visited, vector<int> adj[], stack<int>& mStack){
	    // mark visited
	    visited[node]=1;
	    
	    // for each adjacent node
	    for(auto it: adj[node]){
	        if(!visited[it]){
	            dfs(it, visited, adj, mStack);
	        }
	    }
	    
	    // push current node to stack 
	    // done last because sort should happen 
	    mStack.push(node);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visited(V, 0);
	    stack<int> mStack;
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            dfs(i, visited, adj, mStack);
	        }
	    }
	    
	    // our output is in the stack
	    vector<int> ans;
	    while(!mStack.empty()){
	        ans.push_back(mStack.top());
	        mStack.pop();
	    }
	    return ans;
	}
};
