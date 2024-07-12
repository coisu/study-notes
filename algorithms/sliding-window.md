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



