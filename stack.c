#include<stdio.h>
#include<stdlib.h>

typedef struct list{
    int item;
    struct list *next;
} list;