//
// Created by 韩顺 on 2023/6/11.
//
#include <stdlib.h>
#include <stdio.h>

/* 随机返回一个数组元素 */
int randomAccess(int *nums, int size);

int main() {
    int arr[] = {19,67,89,56,76};
    int result = randomAccess((int *) &arr, 5);
    printf("return result is %d", result);
    return 0;
}

int randomAccess(int *nums, int size) {
    // 在区间 [0, size) 中随机抽取一个数字
    int randomIndex = rand() % size;
    // 获取并返回随机元素
    int randomNum = nums[randomIndex];
    return randomNum;
}

