// https://leetcode.com/problems/word-break/

class Solution {
public:
    bool driver(int idx, string s, set<string>& dict, vector<int> &dp){
        if(idx>=s.length())return true;
        
        if(dp[idx]!=-1)return dp[idx];
        
        string temp;
        for(int j=idx;j<s.length();j++){
            temp+=s[j];
            if(dict.find(temp)!=dict.end()){
                if(driver(j+1, s, dict, dp))return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> mSet;
        for(auto s:wordDict)mSet.insert(s);
        vector<int> dp(s.length(), -1);
        return driver(0, s, mSet, dp);
    }
};