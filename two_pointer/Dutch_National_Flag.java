// https://leetcode.com/problems/sort-colors/

class Solution {
	void sortTheArray (int[] a) {
	    int i=0, j=0, k=a.length-1;
		int temp;
		while(j<=k){
			if(a[j]==1){
				j++;
			}
			else if(a[j]==0){
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
				i++;
				j++;
			}else{
				temp=a[j];
				a[j]=a[k];
				a[k]=temp;
				k--;
			}
		}
	}
}