/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105*/
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int cap = 1000;
    int** res = malloc(sizeof(int*) * cap);
    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int l = i + 1;
        int r = numsSize - 1;

        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];

            if (sum == 0) {
                if (*returnSize == cap) {
                    cap *= 2;
                    res = realloc(res, sizeof(int*) * cap);
                }

                res[*returnSize] = malloc(sizeof(int) * 3);
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[l];
                res[*returnSize][2] = nums[r];
                (*returnSize)++;

                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r--;
                l++;
                r--;
            } else if (sum < 0) {
                l++;
            } else {
                r--;
            }
        }
    }

    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return res;
}