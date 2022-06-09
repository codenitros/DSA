// https://leetcode.com/problems/valid-parentheses/

class Solution {
    private Stack<Character> mStack = new Stack<Character>();
    
    public boolean isValid(String s) {
        
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='(' || s.charAt(i)=='{' || s.charAt(i)=='['){
                mStack.push(s.charAt(i));
            }else{
                if(s.charAt(i)==')'){
                    if(mStack.size()==0 || mStack.peek()!='('){
                        return false;
                    }else{
                        mStack.pop();
                    }                    
                }else if(s.charAt(i)==']'){
                     if(mStack.size()==0 || mStack.peek()!='['){
                        return false;
                    }else{
                        mStack.pop();
                    }                   
                }else if(s.charAt(i)=='}'){
                    if(mStack.size()==0 || mStack.peek()!='{'){
                        return false;
                    }else{
                        mStack.pop();
                    }
                }

            }
        }
        
        return mStack.isEmpty();
    }
}