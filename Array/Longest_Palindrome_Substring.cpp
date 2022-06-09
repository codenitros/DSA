//https://leetcode.com/problems/longest-palindromic-substring/


// expand middle technique

class Solution {
public:
    int expand(string s, int i, int j){
        int n = s.length();
        while(i>=0 && j<n && s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }
    

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        int n = s.length();
        if(n==1)return s;
        
        // consider each as mid and expand both sides
        for(int i=0;i<n;i++){
            
            int len1 = expand(s, i, i); // odd length
            int len2 = expand(s, i, i+1); // even length
            int len =  max(len1, len2);
            //cout<<len<<endl;
            if(len > end - start){
                start = i - (len -1)/2; 
                end = i + len/2;
            }
        }
        //cout<<start<<" "<<end;
        
        return s.substr(start, end-start+1);
    }
};