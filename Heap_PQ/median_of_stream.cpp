// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1#

class Solution
{
    
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;
    
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(small.empty() || small.top() > x){
            small.push(x);
        }else{
            big.push(x);
        }
        
        // our insertion logic may always insert to same pQ 
        // so we can have difference in size of at most 1
        // so call balance after eevery insert
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(small.size() > big.size()+1){
            big.push(small.top());
            small.pop();
        }else if(big.size() > small.size()+1){
            small.push(big.top());
            big.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(small.size()==big.size()){
            return (small.top()+big.top())/2.0;
        }else if(small.size()>big.size()){
            return small.top();
        }else{
            return big.top();
        }
    }
};

