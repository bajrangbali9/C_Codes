#include<stdio.h>
#include<stdlib.h>

typedef struct list{
    int item;
    struct list *next;
} list;

list *search_list(list *l , int x){
    if(l == NULL){
        return NULL;
    }
    if((*l).item == x){
        return l;
    }
    else{
        return search_list((*l).next , x);
    }
}

void insert_list(list **l , int x){
    list *p;
    p = (list*)malloc(sizeof(list));
    p->item = x;
    p->next = *l;
    *l = p;
}

list *item_ahead(list *l , list *x){
    if(l == NULL || l->next == NULL){
        return(NULL);
    }
    if(l->next == x){
        return(l);
    }
    else{
        return(item_ahead(l->next , x));
    }
}

void delete_list(list **l , list **x){
    list *p;
    list *pred;
    p = *l;
    pred = item_ahead(*l , *x);
    if(pred == NULL){
        *l = p->next;
    }
    else{
        pred->next = (*x)->next;
    }
    free(*x);
}
