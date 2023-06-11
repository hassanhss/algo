//
// Created by 韩顺 on 2023/6/11.
//
#include <stdio.h>
#include <stdlib.h>

void pointer_array_one();

void deal_array();

int *extend(const int *nums, int size, int enlarge);

void use_extend();

int main() {
    use_extend();
    return 0;
}

void use_extend() {
    int a[3] = {1, 2, 3};
    int *p =  extend((const int *) &a, 3, 2);
    for (; p < p + 5; p++)    {
        printf("value is %d \n", *p);
    }

//    for (int i = 0; i <5; ++i) {
//        printf("value is %d \n", p[i]);
//    }

    free(p); // 释放指针所指向的内存空间
}

int *extend(const int *nums, int size, int enlarge){
    // 初始化一个扩展长度后的数组
    int *res = malloc(sizeof(int) * (size + enlarge));

    // 将原数组中的所有元素复制到新数组
    for (int i = 0; i < size; i++) {
        res[i] = nums[i];
    }

    // 初始化扩展后的空间
    for (int i = size; i < size + enlarge; i++) {
        res[i] = 0;
    }

    // 返回扩展后的新数组
    return res;
}

void deal_array() {
    int a[5] = {1,2,3,4,5};
    int sum = 0;
    int *p;

    // 指针变量p初始指向a[0]，每次执行循环时对p进行自增；因此p先指向a[1]，然后指向a[2]，依此类推。
    // 在p指向数组a的最后一个元素后循环终止。

    // for语句中的条件p < &a[N]值得特别说明一下。尽管元素a[N]不存在（数组a的下标从0到N-1），
    // 但是对它使用取地址运算符是合法的。因为循环不会尝试检查a[N]的值，所以在上述方式下使用a[N]是
    // 非常安全的。执行循环体时p依次等于&a[0],&a[1],…,&a[N-1]，但是当p等于&a[N]时，循环终止。

//    for (p = &a[0]; p < &a[5]; p++) {
//        sum += *p;
//    }

    // 可以用数组的名字作为指向数组第一个元素的指针
    // 下面是更通用的写法
//    for (p = a; p < a + 5; p++)
//        sum += *p;

    // 用指针作为数组名
    p = a;
    for (int i = 0; i < 5; i++)
        sum += p[i];

    printf("result is %d \n", sum);
}

void pointer_array_one() {
    int a[3] = {1, 2, 3};
    int *p;
    // 通过下列写法可以使p指向a[0]
    p = &a[0];

    // 通过下列写法把值5存入a[0]中
    *p = 6;
    for (int i = 0; i < 3; ++i) {
        printf("value is %d \n",*p++);
    }
}
