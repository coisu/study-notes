# Sliding Window Algorithm

## Introduction
The Sliding Window algorithm is a technique used for solving problems that involve a contiguous subset of elements from an array or list. This technique is particularly useful for problems involving subarrays, substrings, or sequences.

## Problem Statement
Find a subarray or subsequence that satisfies certain conditions within a larger array or sequence.

## Algorithm Steps
1. **Initialize**:
   - Define the window size or condition.
   - Initialize pointers (usually start and end) to define the window boundaries.
2. **Expand** the window by moving the end pointer to include more elements.
3. **Shrink** the window by moving the start pointer to exclude elements when the condition is met or exceeded.
4. **Update** the result based on the current window.
5. Repeat the process until the end pointer reaches the end of the array.

## Pseudocode
```pseudo
function slidingWindow(arr, k):
    window_sum = 0
    max_sum = -infinity
    start = 0
    
    for end in range(0, len(arr)):
        window_sum += arr[end]
        
        if end >= k - 1:
            max_sum = max(max_sum, window_sum)
            window_sum -= arr[start]
            start += 1
    
    return max_sum
```
## Code Implementation
```Code Implementation
def sliding_window_max_sum(arr, k):
    window_sum = 0
    max_sum = float('-inf')
    start = 0
    
    for end in range(len(arr)):
        window_sum += arr[end]
        
        if end >= k - 1:
            max_sum = max(max_sum, window_sum)
            window_sum -= arr[start]
            start += 1
    
    return max_sum

# Example usage:
arr = [2, 1, 5, 1, 3, 2]
k = 3
print(sliding_window_max_sum(arr, k))  # Output: 9
```

## Time Complexity
The algorithm runs in O(n) time complexity, where n is the number of elements in the array, since each element is added and removed from the window exactly once.

## Space Complexity
The algorithm uses O(1) extra space, as only a few variables are used to store the sum and maximum sum.

## Example
Consider the array [2, 1, 5, 1, 3, 2] and window size k = 3:

   Initial window: [2, 1, 5], sum = 8
   Slide window: [1, 5, 1], sum = 7
   Slide window: [5, 1, 3], sum = 9
   Slide window: [1, 3, 2], sum = 6
   Maximum sum found: 9
   
## Use Cases
Maximum sum of subarrays of size k.
Longest substring with at most k distinct characters.
Minimum size subarray sum.
Problems involving contiguous subarrays or subsequences.

## References
GeeksforGeeks: Sliding Window
LeetCode: Sliding Window Problems
Wikipedia: Sliding Window Protocol
