// https://leetcode.com/problems/largest-number/

// if we concatenate in both ways and check we will know which is greater
// eg 32 and 34
// 3234 or 3432 clearly 3432 is greater
bool comparator(string a, string b){
    return a+b>b+a;  
}
    
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStrings;
        
        for(auto i:nums){
            numStrings.push_back(to_string(i));
        }
        sort(numStrings.begin(), numStrings.end(), comparator);
        
        string ans="";
        for(auto num:numStrings){
            ans+=num;
        }
        
        // get rid of preceding zeroes 
        while(ans[0]=='0' && ans.length()>1){
            ans.erase(0, 1);
        }
        
        
        return ans;
    }
};