//https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // use dequeue -- doubly linked list
        int n=nums.size();
        
        deque<int> dQ;
        vector<int> ans;
        for(int i=0;i<n;i++){
            // this logic checks if front element is getting lost when we move 
            if(!dQ.empty() && dQ.front()==i-k){
                dQ.pop_front();
            }
            
            // if incoming number is greater than back get rid of smaller number
            while(!dQ.empty() && nums[dQ.back()] <= nums[i]){
                dQ.pop_back();
            }
            
            dQ.push_back(i);
            
            // from i=k-1 for every move we need to tell boundary max 
            if(i >= k-1)ans.push_back(nums[dQ.front()]);
        }
        return ans;
    }
};