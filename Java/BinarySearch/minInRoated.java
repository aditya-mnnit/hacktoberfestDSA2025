package BinarySearch;
///Problem Statement:given an integer array arr of size N, sorted in ascen
/// ding order (with distinct values), the array is rotated at any index which is unknown. Find the m
/// inimum element in the array.

public class minInRoated {
    public static void main(String[] args) {

        // Input array
        int[] nums = {4, 5, 6, 7, 0, 1, 2};

        // Create object of Solution
        Solution sol = new Solution();

        // Call function and store result
        int result = sol.findMin(nums);

        // Output the result
        System.out.println("Minimum element is " + result);
    }
}

class Solution {
    public int findMin(int[] nums) {
        int low =0;
        int end = nums.length-1;
        while(low<=end) {
            int mid = (low+end)/2;
            if(nums[mid]>nums[end]) {
                low=mid+1;
            } else{
                end = mid-1;
            }
        }
        return nums[low];
    }
}


