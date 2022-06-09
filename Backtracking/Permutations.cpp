// https://leetcode.com/problems/permutations/

class Solution {
public:
    void getAllPermutations(vector<int>& ds, vector<int>& nums, 
                            int freq[], vector<vector<int>>& ans){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        
        // for all possible value
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i]=1;
                ds.push_back(nums[i]);
                getAllPermutations(ds, nums, freq, ans);
                // backtrack
                ds.pop_back();
                freq[i]=0;
            }
        }
        
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        vector<int> ds;
        int freq[n];
        for(int i=0;i<n;i++)freq[i]=0;
        
        getAllPermutations(ds, nums, freq, ans);
        return ans;
    }
};