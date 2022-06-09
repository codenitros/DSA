// https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1


class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int> pQ;
	    for(int i=0;i<n;i++){
	        pQ.push(arr[i]);
	    }
	    vector<int> ans;
	    while(k-- && !pQ.empty()){
	        ans.push_back(pQ.top());
	        pQ.pop();
	    }
	    
	    return ans;
	}

};