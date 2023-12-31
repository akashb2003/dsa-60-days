// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

class Solution {
public:

    int findPivot(vector<int>& nums){
            int s=0, e = nums.size()-1, m = s+(e-s)/2;

            while(s<e){
                if(nums[s]<=nums[e]) return s;

                if(nums[m]>=nums[0]){
                    s = m+1;
                }
                else{
                    e = m;
                }
                 m = s+(e-s)/2;
            }
            return s;
        }

    int binSearch(vector<int>& nums,int s,int e, int target){
        int m = s+(e-s)/2;

        while(s<=e){
            if(nums[m]==target){
                return m;
            }
            if(nums[m]> target){
                e  = m-1;
            }
            else{
                s = m+1;
            }
            m = s+(e-s)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {

        int pivot = findPivot(nums);
        int e= nums.size()-1;
        if(target>= nums[pivot] && target<=nums[e]){
            return binSearch(nums,pivot, e,target);
        }
        else {
            return binSearch(nums,0, pivot-1 ,target);
        }
   
    }
};
