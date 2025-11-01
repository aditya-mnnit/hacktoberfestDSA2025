package BinarySearch;

public class floorCeil {
    public static void main(String[] args) {
        int[] arr = {3, 4, 4, 7, 8, 10};
        int n = 6, x = 5;
        int[] ans = getFloorAndCeil(arr, x, n);
        System.out.println("The floor and ceil are: " + ans[0]
                           + " " + ans[1]);
       // System.out.println("floor is " + floor(arr, x, n));
    }
    public static int [] getFloorAndCeil(int[] arr, int x , int n) {
        int f = floor(arr,x,n);
        int c = celling(arr, x, n);
        return new int[] {f,c};
    }
    public static int floor(int[] arr, int x, int n ) {
        int start = 0;
        int end = n-1;
        int ans = -1;
        while(start<= end) {
            int mid = (start+end)/2;
            if(arr[mid]<=x) {
                ans = mid;
                start = mid+1;
                
            }else {
                end = mid -1;               
            }
            
        }return arr[ans];
    }
    public static int celling(int [] arr, int x,  int n) {
        int start = 0 ;
        int end = n-1;
        int ans = n;
        while(start<=end) {
            int mid = (start+end)/ 2;
            if(arr[mid] >= x){
                ans = mid;
                end = mid -1;
            }else {
                start = mid + 1;
            }
        }return arr[ans] ;
    }
}
