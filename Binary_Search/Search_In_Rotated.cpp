// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int binarySearch(vector<int> & nums, int target){
        int beg=0, end=nums.size()-1;

        while(beg<=end){
            int mid = beg + (end - beg)/2;
            
            if(nums[mid]==target)return mid;
            if(nums[mid] >= nums[beg]){
                // [4,5,6,0,1,2,2]
                if(target < nums[mid] && nums[beg] <= target){
                    end=mid-1;
                }else{
                    beg=mid+1;
                }
            }else{
                if(target > nums[mid] && nums[end] >= target){
                    beg=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target);
    }
};