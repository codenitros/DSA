//https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int  maxi=0;
        int htj, hti;
        while(i<j){
            maxi=max(maxi, min(height[i],height[j])*abs(i-j));

            if(height[i] > height[j]){
                htj = height[j];
                while(height[j]<=htj && j>i )j--;
            }else{
                hti = height[i];
                while(height[i]<=hti && i<j )i++;
            }
        }
        return maxi;
    }
};


