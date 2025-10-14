"""
Radix Sort Algorithm Implementation

Radix Sort sorts integers by processing individual digits from least 
significant to most significant. Uses counting sort as subroutine.

Time Complexity: O(d * (n + k))
Space Complexity: O(n + k)
Stable: Yes
"""

def counting_sort_for_radix(arr, exp):
    """
    Counting sort subroutine for radix sort.
    Sorts array based on digit at position exp.
    """
    n = len(arr)
    output = [0] * n
    count = [0] * 10
    
    for i in range(n):
        index = (arr[i] // exp) % 10
        count[index] += 1
    
    for i in range(1, 10):
        count[i] += count[i - 1]
    
    for i in range(n - 1, -1, -1):
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
    
    return output


def radix_sort(arr):
    """
    Radix Sort implementation.
    Sorts non-negative integers using radix sort algorithm.
    """
    if not arr:
        return arr
    
    if any(x < 0 for x in arr):
        raise ValueError("Radix sort only works with non-negative integers")
    
    max_num = max(arr)
    exp = 1
    
    while max_num // exp > 0:
        arr = counting_sort_for_radix(arr, exp)
        exp *= 10
    
    return arr


def radix_sort_with_steps(arr):
    """
    Radix Sort with step-by-step visualization.
    """
    if not arr:
        return arr, []
    
    if any(x < 0 for x in arr):
        raise ValueError("Radix sort only works with non-negative integers")
    
    steps = []
    max_num = max(arr)
    exp = 1
    
    print("Radix Sort Process:")
    print(f"Original array: {arr}")
    print(f"Maximum number: {max_num}")
    print(f"Number of digits: {len(str(max_num))}")
    
    step_count = 1
    while max_num // exp > 0:
        print(f"\nStep {step_count}: Sorting by digit at position {exp}")
        
        digits = [(num, (num // exp) % 10) for num in arr]
        print(f"Current digits: {digits}")
        
        arr = counting_sort_for_radix(arr, exp)
        
        print(f"After sorting: {arr}")
        steps.append({
            'step': step_count,
            'position': exp,
            'array': arr.copy(),
            'digits': digits
        })
        
        exp *= 10
        step_count += 1
    
    print(f"\nFinal sorted array: {arr}")
    return arr, steps


# =========================================================
# Testing and Examples
# =========================================================

def test_radix_sort():
    """Test function to demonstrate radix sort with various examples."""
    
    print("=" * 60)
    print("RADIX SORT TESTING")
    print("=" * 60)
    
    # Test Case 1: Basic example
    print("\nTest Case 1: Basic Example")
    arr1 = [170, 45, 75, 90, 2, 802, 24, 66]
    print(f"Input: {arr1}")
    sorted_arr1 = radix_sort(arr1.copy())
    print(f"Output: {sorted_arr1}")
    print(f"Correct: {sorted_arr1 == sorted(arr1)}")
    
    # Test Case 2: Single element
    print("\nTest Case 2: Single Element")
    arr2 = [42]
    print(f"Input: {arr2}")
    sorted_arr2 = radix_sort(arr2.copy())
    print(f"Output: {sorted_arr2}")
    
    # Test Case 3: Already sorted
    print("\nTest Case 3: Already Sorted")
    arr3 = [1, 2, 3, 4, 5]
    print(f"Input: {arr3}")
    sorted_arr3 = radix_sort(arr3.copy())
    print(f"Output: {sorted_arr3}")
    
    # Test Case 4: Reverse sorted
    print("\nTest Case 4: Reverse Sorted")
    arr4 = [1000, 100, 10, 1]
    print(f"Input: {arr4}")
    sorted_arr4 = radix_sort(arr4.copy())
    print(f"Output: {sorted_arr4}")
    
    # Test Case 5: With zeros
    print("\nTest Case 5: With Zeros")
    arr5 = [0, 100, 0, 50, 0]
    print(f"Input: {arr5}")
    sorted_arr5 = radix_sort(arr5.copy())
    print(f"Output: {sorted_arr5}")
    
    # Test Case 6: Large numbers
    print("\nTest Case 6: Large Numbers")
    arr6 = [999999, 123456, 789012, 345678]
    print(f"Input: {arr6}")
    sorted_arr6 = radix_sort(arr6.copy())
    print(f"Output: {sorted_arr6}")
    
    # Test Case 7: Empty array
    print("\nTest Case 7: Empty Array")
    arr7 = []
    print(f"Input: {arr7}")
    sorted_arr7 = radix_sort(arr7.copy())
    print(f"Output: {sorted_arr7}")
    
    # Test Case 8: Error case - negative numbers
    print("\nTest Case 8: Error Case - Negative Numbers")
    arr8 = [5, -2, 8, 1]
    print(f"Input: {arr8}")
    try:
        sorted_arr8 = radix_sort(arr8.copy())
        print(f"Output: {sorted_arr8}")
    except ValueError as e:
        print(f"Error: {e}")


def compare_with_other_sorts():
    """Compare radix sort with other sorting algorithms."""
    
    print("\n" + "=" * 60)
    print("PERFORMANCE COMPARISON")
    print("=" * 60)
    
    import time
    import random
    
    sizes = [100, 1000, 10000]
    
    for size in sizes:
        print(f"\nTesting with {size} elements:")
        
        arr = [random.randint(0, 999999) for _ in range(size)]
        
        start_time = time.time()
        radix_sorted = radix_sort(arr.copy())
        radix_time = time.time() - start_time
        
        start_time = time.time()
        builtin_sorted = sorted(arr.copy())
        builtin_time = time.time() - start_time
        
        print(f"  Radix Sort: {radix_time:.6f} seconds")
        print(f"  Built-in Sort: {builtin_time:.6f} seconds")
        print(f"  Results match: {radix_sorted == builtin_sorted}")


if __name__ == "__main__":
    test_radix_sort()
    compare_with_other_sorts()
    
    print("\n" + "=" * 60)
    print("STEP-BY-STEP DEMONSTRATION")
    print("=" * 60)
    
    demo_arr = [329, 457, 657, 839, 436, 720, 355]
    sorted_demo, steps = radix_sort_with_steps(demo_arr.copy())
    
    print(f"\nSummary:")
    print(f"  Original: {demo_arr}")
    print(f"  Sorted:   {sorted_demo}")
    print(f"  Steps:    {len(steps)}")
