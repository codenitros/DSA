// https://leetcode.com/problems/longest-palindromic-substring





int expand(int i, int j, string s){
	while(s[i]==s[j] && i>=0 && j<s.length()){
		i--;
		j++;
	}
	
	return j-i-1;
}

string getLongestPalindrome(string s) {
    // expand around center
	int n=s.length();
	int maxi=INT_MIN;
	string ans="";
	
	int start=0, end=0;
	
	for(int i=0;i<n;i++){
		int len1 = expand(i, i, s);
		int len2 = expand(i, i+1, s);
		int len = max(len1, len2);
		
		if(len > (end-start) && len>maxi){
			maxi=len;
			start = i - (len-1)/2; 
			end = i + len/2;
			ans = s.substr(start, end - start + 1);
		}
	}
	
	return ans;
}