#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 100006

typedef struct Node{
    int data;
    struct Node *r;
}Node;

Node *head,*tail;
// 头部插入一个数 0 末尾 1 头上
void insert_1(int data){
    Node *tmp = (Node*)malloc(sizeof(Node)) ;
    tmp->data = data;
    tmp->r = head;
    head = tmp;
}
void insert_0(int data){
    Node *tmp = (Node*)malloc(sizeof(Node)) ;
    tmp->data = data;
    tail->r = tmp;
    tail = tmp;
}
void Delet(int x){
    Node *now = head;
    if(x==1){
        head = head->r;
        free(now);
        return ;
    }
    x-=2;
    while(x-->0) now = now->r;
    Node *tmp = now->r;
    now->r = now->r->r;
    if(now->r == NULL) tail = now;
    free(tmp);
}
void init(){
    Node *tmp = (Node*)malloc(sizeof(Node)) ;
    tmp->data = 1;
    tmp->r = NULL;
    head = tmp;
    tail = tmp;
}
void C(){
    tail->r = head;
}
/*
1 2 1 1 1 2 1 1 1 1 2 2 2 2 1 2 1 1 3 1 1 2 1 2 2 2 2 1 1 2 2 1 1 1
*/
int main()
{
    init();
    char c;
    while(scanf("%c",&c)){
       
        if(c=='T'){
            int x;
            scanf("%d",&x);insert_0(x); //printf("%d\n",1);
            scanf("%d",&x);insert_0(x);
            scanf("%d",&x);insert_0(x);
        }
        if(c=='H'){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            insert_1(z);
            insert_1(y);
            insert_1(x);
        }
        if(c=='D'){
            int x;
            scanf("%d",&x);Delet(x);
        }
        if(c=='C'){
            C();
            break;
        }
    }


    // 1 2 1 1 1 2 1 1 1 1 2 2 2 2 1 2 1 1 3 1 1 2 1 2 2 2 2 1 1 2 2 1 1 1
    Node * now = head;

    while(now->data != 3) 
    now = now->r;

    for(int x=1;;x++){
        if(now->r==now){
            printf("%d ",now->data);
            break;
        }
        for(int j=1;j<x;j++) now = now->r;
        Node * las = now;
        while(las->r!=now) las = las->r;
        las->r = now->r;
        printf("%d ",now->data);
        now = now->r;
    }


    return 0;
}
// 3121112212212212112111211211212211