//
// Created by 韩顺 on 2023/6/11.
//
#include <stdlib.h>
#include <string.h>
#include "stdio.h"

//  I             1
//  V             5
//  X             10
//  L             50
//  C             100
//  D             500
//  M             1000

//  I可以放在V(5) 和X(10) 的左边，来表示 4 和 9
//  X可以放在L(50) 和C(100) 的左边，来表示 40 和90
//  C可以放在D(500) 和M(1000) 的左边，来表示400 和 900


int romanToInt(char * s);

int main() {
    char *str = "LVIII";
    int result = romanToInt(str);
    printf("result is %d ", result);
    return 0;
}

int romanToInt(char * s) {
    // 在这个函数中，将字符'A'的ASCII码值减去，是为了将每个罗马数字符号映射到一个0到25的数值，
    // 从而可以使用一个长度为26的数组来存储每个符号对应的数值。不减去'A'，则需要创建一个为90的
    // 数组来存储每个字符对应的数值，这样会浪费很多空间。
    int symbolValues[26];
    symbolValues['I' - 'A'] = 1;
    symbolValues['V' - 'A'] = 5;
    symbolValues['X' - 'A'] = 10;
    symbolValues['L' - 'A'] = 50;
    symbolValues['C' - 'A'] = 100;
    symbolValues['D' - 'A'] = 500;
    symbolValues['M' - 'A'] = 1000;
    int ans = 0;
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        int value = symbolValues[s[i] - 'A'];
        if (i < n - 1 && value < symbolValues[s[i + 1] - 'A']) {
            ans -= value;
        } else {
            ans += value;
        }
    }
    return ans;
}

// 从本质而言，C语言把字符串字面量作为字符数组来处理。当C语言编译器在程序中遇到长度为 n 的字符串字面量时，
// 它会为字符串字面量分配长度为 n+1 的内存空间。这块内存空间将用来存储字符串字面量中的字符，以及一个用来
// 标志字符串末尾的额外字符（空字符）。空字符是一个所有位都为0的字节，因此用转义序列\0来表示。

// 下面统计单词的函数
int char_array(const char s[]) {
    int count = 0, i;
    for (i = 0; s[i] != '\0';  i++)
        if (s[i] == ' ')
            count++;
    return count;
}

int char_pointer(const char *s) {
    int count = 0;
    for (; *s != '\0'; s++)
        if (*s == ' ')
            count++;
    return count;
}

int char_pointer_another(const char *s) {
    int n = strlen(s);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == ' ')
            count++;
    }
}


// 问题：
//      1.字符串的定义
            // 通常情况下可以在任何C语言允许使用char *指针的地方使用字符串字面量，
            // 比如 char *p = "abc"、char ch[8] = "June 14"或者char ch[] = "June 14"
//      2.字符串转化为字符数组，遍历
            // 字符串是以数组的方式存储的，因此可以使用下标来访问字符串中的字符。例如，为了对字符串s中的每个字符进行处理，
            // 可以设定一个循环来对计数器i进行自增操作，并通过表达式s[i]来选择字符。例如上面的char_array函数变量

            // 当字符串是以指针的方式存在的时候，可以通过指针的属性来方位字符串，例如上面的函数char_pointer
