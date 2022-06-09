//https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1


class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> mQ;
		    vector<int> seen(26, 0);
		    
		    int i=0;
		    int n=A.length();
		    string ans="";
		    while(i<n){
		        seen[A[i]-'a']++;
		        mQ.push(A[i]);
		        
		        while(!mQ.empty() && seen[mQ.front()-'a']>1){
		            mQ.pop();
		        }
		        if(mQ.empty()){
		            ans+='#';
		        }else{
		            ans+=mQ.front();
		        }
		        
		        i++;
		    }
		    return ans;
		}

};