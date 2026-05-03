/*You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7*/
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int* result = malloc(*returnSize * sizeof(int));
    int* dq = malloc(numsSize * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < numsSize; i++) {
        if (front < rear && dq[front] < i - k + 1) front++;
        while (front < rear && nums[dq[rear - 1]] <= nums[i]) rear--;
        dq[rear++] = i;
        if (i >= k - 1) result[i - k + 1] = nums[dq[front]];
    }

    free(dq);
    return result;
}