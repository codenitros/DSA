// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int res=0;
        
        vector<bool> ch(256, false);
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(ch[s[j]])break;
                else{
                    res=max(res,j-i+1);
                    ch[s[j]]=true;
                }
            }
            fill(ch.begin(), ch.end(), false); // reset our map
        }
        return res;
    }
};