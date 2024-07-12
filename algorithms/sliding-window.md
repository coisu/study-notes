# Sliding Window Algorithm

## Introduction
The Sliding Window algorithm is a technique used for solving problems that involve a contiguous subset of elements from an array or list. This technique is particularly useful for problems involving subarrays, substrings, or sequences.

슬라이딩 윈도우 알고리즘은 배열에서 일정 크기의 구간을 이동하면서 문제를 해결하는 알고리즘으로
보통 부분배열의 합, 최솟값, 최댓값등을 구할 때 자주 사용된다. 이름 그대로 창문처럼 고정된 하위배열의 틀을 배열 상에서 이동시키면서 해당 배열의 원소를 확인한다.

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
## Code Implementation - Python
```python
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
[GeeksforGeeks: Sliding Window - Technique](https://www.geeksforgeeks.org/window-sliding-technique/)

[GeeksforGeeks: Sliding Window - Problem](https://www.geeksforgeeks.org/sliding-window-problems-identify-solve-and-interview-questions/)

[LeetCode: Sliding Window Problems](https://leetcode.com/problems/count-number-of-nice-subarrays/?envType=daily-question&envId=2024-06-25)

[Wikipedia: Sliding Window Protocol](https://en.wikipedia.org/wiki/Sliding_window_protocol)
