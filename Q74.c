/*You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.*/


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int k;
    int *a;
    int size;
} KthLargest;

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *obj = malloc(sizeof(KthLargest));
    obj->k    = k;
    obj->size = numsSize;
    obj->a    = malloc((numsSize + 10000) * sizeof(int));

    for (int i = 0; i < numsSize; i++)
        obj->a[i] = nums[i];

    // sort descending (bubble sort)
    for (int i = 0; i < numsSize - 1; i++)
        for (int j = i + 1; j < numsSize; j++)
            if (obj->a[i] < obj->a[j]) {
                int t = obj->a[i];
                obj->a[i] = obj->a[j];
                obj->a[j] = t;
            }

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    
    int i = 0;
    while (i < obj->size && obj->a[i] > val)
        i++;

    for (int j = obj->size; j > i; j--)
        obj->a[j] = obj->a[j - 1];

    obj->a[i] = val;
    obj->size++;

    return obj->a[obj->k - 1];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->a);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/