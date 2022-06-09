// https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        
        int i=0;
        int ans=0;
        while(i<s.length()){
            if(s[i]=='('){
                stk.push(i); //push index
            }
            else {
                stk.pop();
                if(stk.empty()){ // stack should not go empty, we need something to get our length
                    stk.push(i); 
                }else{
                    int len = i - stk.top();
                    ans = max(ans, len);
                }
            } 
            i++;
        }
        return ans;
    }
};