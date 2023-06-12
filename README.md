1.两数之和总结
- 指针传递问题，returnSize首先定义为基本类型，然后通过指针的方式进行传递过去
- 返回的指针数组通过数组下标的方式进行访问，不能使用指针的方式来访问，因为我们不知道，数组结束的地方在哪里

2.罗马数字总结
C语言把字符串字面量作为字符数组来处理。当C语言编译器在程序中遇到长度为 n 的字符串字面量时，它会为字符串字面量
分配长度为 n+1 的内存空间。这块内存空间将用来存储字符串字面量中的字符，以及一个用来标志字符串末尾的额外字符（空字符）。
空字符是一个所有位都为0的字节，因此用转义序列\0来表示。

可以通过如下的方式创建字符串
~~~
char *p = "abc";
char ch[8] = "June 14";
char ch[] = "June 14";
~~~

字符串是以数组的方式存储的方式访问
~~~
int char_array(const char s[]) {
    int count = 0, i;
    for (i = 0; s[i] != '\0';  i++)
        if (s[i] == ' ')
            count++;
    return count;
}
~~~

字符串是以指针的方式存储的方式访问
~~~
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
~~~