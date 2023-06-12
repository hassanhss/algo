//
// Created by 韩顺 on 2023/6/11.
//
#include <stdbool.h>
#include <string.h>
#include "stdio.h"

bool isPalindrome(int x);

int main() {
    int num = 121;
    bool result = isPalindrome(num);
    printf("result is  %d", result);
    return 0;
}

bool isPalindrome(int x) {
    char str[20];
    sprintf(str, "%d", x);
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}