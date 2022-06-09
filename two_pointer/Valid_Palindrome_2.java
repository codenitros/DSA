// https://leetcode.com/problems/valid-palindrome-ii/


class Solution {
    public boolean validPalindrome(String s) {
        int i=0, j=s.length()-1;
        int cnt1=0, cnt2=0;
        
        while(i<j){
            if(s.charAt(i)==s.charAt(j)){
                i++;
                j--;
            }else{
                cnt1++;
                i++;
            }
        }
        
        i=0;
        j=s.length()-1;
        
        while(i<j){
            if(s.charAt(i)==s.charAt(j)){
                i++;
                j--;
            }else{
                cnt2++;
                j--;
            }
        }
        
        if(cnt1==1 || cnt2==1)return true; // max deletion is one
        if(cnt1==0 || cnt2==0)return true; // string already a palindrom
        return false;
        
    }
}