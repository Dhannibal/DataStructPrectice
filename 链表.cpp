#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    node* nex;
};

typedef struct{
    node* head;
    int length;
}sqList;

//创建节点
node* newNode() {
    node* Node = (node *)malloc(sizeof(node));
    Node->nex = NULL;
    Node->val = -1;
    return Node;
}

//初始化
void init(sqList& L) {
    L.head = newNode();
    L.length = 0;
}

//把x插入到第p个位置[1, length+1]上
bool insert(sqList& L, int p, int x) {
    p--;//转化成下标
    if(p < 0 || p > L.length) return false;
    node* temp = newNode();
    temp->val = x;

    int cnt = 0;
    node* t = L.head;
    while (t->nex != NULL && cnt < p) {
        t = t->nex;
        cnt++;
    }
    if(t->nex != NULL)
        temp->nex = t->nex;
    t->nex = temp;

    L.length++;
    return true;
}

//删除第p个位置[1, length]上的数
bool del(sqList& L, int p) {
    p--;//转化成下标
    if(p < 0 || p >= L.length) return false;
    int cnt = 0;
    node *t, *s;
    t = L.head;
    while (t->nex != NULL && cnt < p) {
        t = t->nex;
        cnt++;
    }
    s = t->nex;
    t->nex = t->nex->nex;
    free(s);
    L.length--;
    return true;
}

//修改第p个位置[1, length]上的数为x
bool change(sqList& L, int p, int x) {
    p--;//转化成下标
    if(p < 0 || p >= L.length) return false;
    int cnt = 0;
    node* t;
    t = L.head;
    while (t->nex != NULL && cnt < p) {
        t = t->nex;
        cnt++;
    }
    t->nex->val = x;
    return false;
}

//查找第p个位置[1, length]上的数
int SearchByPos(sqList& L, int p) {
    p--;//转化成下标
    if(p < 0 || p >= L.length) return -1;
    int cnt = 0;
    node* t;
    t = L.head;
    while (t->nex != NULL && cnt <= p) {
        t = t->nex;
        cnt++;
    }
    return t->val;
}

// 查找第1个出现x的位置
int SearchByVal(sqList& L, int x) {
    int i = 0;
    for(node* t = L.head->nex; t!= NULL; t = t->nex, i++) {
        if(x == t->val) return i+1;
    }
    return -1;
}

//输出
void print(sqList& L) {
    if(L.length == 0) puts("链表为空!");
    for(node* t = L.head->nex; t!= NULL; t = t->nex) {
        printf("%d%s", t->val, t->nex==NULL?"\n":"->");
    }
}

int main() {
    sqList L;
    init(L);
    insert(L, 1, 3);
    insert(L, 1, 2);
    insert(L, 1, 1);
    print(L);
    insert(L, 2, 0);
    print(L);
    insert(L, 4, 100);
    print(L);
    insert(L, 6, 99);
    print(L);
    del(L, 6);
    print(L);
    printf("%d\n", SearchByVal(L, 100));
    return 0;
}
