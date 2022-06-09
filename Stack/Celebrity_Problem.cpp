// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1


class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> mstk;
        for(int i=0;i<n;i++){
            mstk.push(i);
        }
        
        // every time pop out top two element and compare them
        // push one of those
        // until there is only one person
        while(mstk.size()!=1){
            int x = mstk.top();
            mstk.pop();
            
            int y = mstk.top();
            mstk.pop();
            
            if(M[x][y]==1){ // x cannot be celebrity, push y
                mstk.push(y);
            }else{
                mstk.push(x); // y cannot be celebrity, push x
            }
        }
        
        int a = mstk.top(); 
        int ans = a; // our possible celebrity
        for(int i=0;i<n;i++){
            if(M[a][i]==1){ // celebrity should not know others
                ans=-1;
                break;
            }
            if(i!=a && M[i][a]!=1){ // everyone should know celebrity
                ans=-1;
                break;
            }
        }
        return ans;
    }
};

