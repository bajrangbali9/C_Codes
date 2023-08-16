#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
    int item;
    struct tree *parent;
    struct tree *left;
    struct tree *right;
} tree;

tree *search_tree(tree *l , int x){
    if(l == NULL){
        return(NULL);
    }
    if(l->item = x){
        return(l);
    }
    if(x < l->item){
        return(search_tree(l->left , x));
    }
    else{
        return(search_tree(l->right , x));
    }
}

tree *find_min(tree *t){
    tree *min;
    if(t == NULL){
        return(NULL);
    } 
    min = t;
    while(min->left != NULL){
        min = min->left;
    }
    return(min);
}

tree *find_max(tree *t){
    tree *max;
    if(t == NULL){
        return(NULL);
    }
    max=t;
    while(t->right != NULL){
        max = max->right;
    }
    return(max);
}

void traverse_tree(tree *l){
    if(l != NULL){
        //pre order
        traverse_tree(l->left);
        //in order process_item(l->item);
        traverse_tree(l->right);
        //post order
    }
}

void insert_tree(tree **l , int x , tree *parent){
    tree *p;
    if(*l == NULL){
        p = malloc(sizeof(tree));
        p->item = x;
        p->left = p->right = NULL;
        p->parent = parent;
        *l = p;
        return;
    }
    if(x < (*l)->item){
        insert_tree(&((*l)->left),x,*l);
    }
    else{
        insert_tree(&((*l)->right),x,*l);
    }
}

int main(){

}