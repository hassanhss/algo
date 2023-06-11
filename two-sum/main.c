//
// Created by 韩顺 on 2023/6/11.
//
#include <stdlib.h>
#include "stdio.h"

int* twoSum(const int* nums, int numsSize, int target, int* returnSize);

int main() {
    int nums[4] = {2,7,11,15};
    int target = 9;
    int returnSize = 0;
    int *result = twoSum((int *) &nums, 4, target, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("result is %d \n", result[i]);
    }
    free(result);
    return 0;
}

int* twoSum(const int* nums, int numsSize, int target, int* returnSize){
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                int* ret = malloc(sizeof(int) * 2);
                ret[0] = i, ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

// 总结