package BinarySearch;

public class searchWithDup {
    public static void main(String[] args) {
        int[] arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
        int k = 3;
        boolean ans = searchInARotatedSortedArrayII(arr, k);
        if (ans == false)
            System.out.println("Target is not present.");
        else
            System.out.println("Target is present in the array.");
    }
    public static boolean searchInARotatedSortedArrayII(int[]arr,int k) {
        int n = arr.length;
        int low = 0;
        int end = n-1;
        while(low<=end) {
        int mid = (low+end)/2;
        if(arr[mid]==k) return true;
        if(arr[low]==arr[end] && arr[end]==arr[mid]) {
            low=low+1;
            end = end -1;
            continue;
        }
        //left
        if(arr[mid]>=arr[low]) {
            if(arr[mid]>=k && arr[low]<=k) {
                end = mid -1;
            } else {
                low = mid +1;
            }
        }
        //right
        else{
            if(arr[mid]<=k && arr[end]>=k) {
                low= mid+1;
            }else{
                end = mid -1;
            }
        }
    }
    return false;
    }
    
}
