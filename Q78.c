/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]

 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int freq[20001];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < numsSize; i++)
        freq[nums[i] + 10000]++;

    int *h = malloc(numsSize * sizeof(int));
    int *hv = malloc(numsSize * sizeof(int));
    int hn = 0;

    for (int i = 0; i < 20001; i++) {
        if (!freq[i]) continue;
        h[hn] = freq[i]; hv[hn] = i - 10000; hn++;
        int j = hn - 1;
        while (j > 0 && h[(j-1)/2] > h[j]) {
            int t = h[(j-1)/2]; h[(j-1)/2] = h[j]; h[j] = t;
            t = hv[(j-1)/2]; hv[(j-1)/2] = hv[j]; hv[j] = t;
            j = (j-1)/2;
        }
    }