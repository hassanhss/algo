#include <stdio.h>
#include <stdlib.h>

//
// Created by 韩顺 on 2023/6/11.
//
struct ListNode{
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

ListNode *newListNode(int val);

ListNode *initNode();

int main() {
    ListNode *list = initNode();
    for (; list->next != NULL; list = list->next) {
        printf("list value -> %d \n", list->val);
    }
    return 0;
}

ListNode *initNode(){
    ListNode *header = newListNode(1);
    ListNode *one = newListNode(2);
    ListNode *two = newListNode(3);
    ListNode *three = newListNode(4);
    header->next = one;
    one->next = two;
    two->next = three;
    three->next = NULL;
    return header;
}

ListNode *newListNode(int val) {
    ListNode *node;
    node = malloc(sizeof (ListNode));
    node -> val = val;
    node -> next = NULL;
    return node;
}