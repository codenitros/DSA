// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1



class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long int> mStk;
        vector<long long> vec(n,0);

        vec[n-1]=-1; // given condition as per question
        mStk.push(arr[n-1]); // last element of arr will be on top first
        
        int i=n-2; // start from end
        while(i>=0){
            while(!mStk.empty() && mStk.top()<arr[i]){
                mStk.pop(); // no use of smaller elements
            }
            if(mStk.empty()){
                mStk.push(arr[i]);
                vec[i]=-1;
            }else{
                vec[i]=mStk.top();
                mStk.push(arr[i]);
            }
            i--;
        }
        return vec;
    }
};