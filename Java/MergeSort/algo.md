Merge Sort

Problem: Sort an array of elements in ascending order using divide-and-conquer.

Algorithm (Stepwise / Pseudocode):

Input: Array A[0..n-1]
Output: Sorted array A

1. If length(A) > 1:
    a. Divide A into two halves: Left and Right
    b. Recursively apply MergeSort to Left and Right
2. Merge the two sorted halves:
    a. Create temporary arrays L[] and R[] for Left and Right
    b. Initialize pointers i = 0, j = 0, k = 0
    c. While i < length(L) and j < length(R):
        - If L[i] ≤ R[j]:
            A[k] = L[i]; i++; k++
        - Else:
            A[k] = R[j]; j++; k++
    d. Copy remaining elements from L[] and R[] (if any) to A
    e. Copy remaining elements from R[] (if any) to A
3. Return A


Time Complexity: O(n log n)
Space Complexity: O(n)