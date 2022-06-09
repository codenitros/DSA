// https://leetcode.com/problems/largest-rectangle-in-histogram/

// at every index get left smaller, get right smaller
// use formula
// (rightsmaller - leftsmaller + 1) * height[idx] 
// return max

// O(N) + O(N) + O(N) + O(N)

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n=height.size();
        int leftSmall[n], rightSmall[n];
        
        stack<int> st;
        
        // fill left smaller list
        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()] >= height[i]){
                st.pop();
            }
            if(st.empty()){
               leftSmall[i] = 0; // no left smaller
            }else{
                leftSmall[i] = st.top() + 1;
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        // fill right smaller list
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && height[st.top()] >= height[i]){
                st.pop();
            }
            if(st.empty()){
               rightSmall[i] = n-1; // no right smaller
            }else{
                rightSmall[i] = st.top() - 1;
            }
            st.push(i);
        }
        
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi, (rightSmall[i]-leftSmall[i]+1)*height[i]);
        }
        
        return maxi;
    }
};