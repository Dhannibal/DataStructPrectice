#include<stdio.h>

const int maxn = 1e5+5;

typedef struct{
    int data[maxn];
    int length;
}sqList;

void init(sqList& L) {
    L.length = 0;
}

//把x插入到第p个位置[1, length+1]上
bool insert(sqList& L, int p, int x) {
    p--;//转化成下标
    if(p < 0 || p > L.length) return false;
    if(L.length == p) {
        L.data[p] = x;
    }
    else {
        for(int i = L.length-1; i >= p; i--) {
            L.data[i+1] = L.data[i];
        }
        L.data[p] = x;
    }
    L.length++;
    return true;
}

//删除第p个位置[1, length]上的数
bool del(sqList& L, int p) {
    p--;//转化成下标
    if(p < 0 || p >= L.length) return false;
    for(int i = p+1; i < L.length; i++) {
        L.data[i-1] = L.data[i];
    }
    L.length--;
    return true;
}

//修改第p个位置[1, length]上的数为x
bool change(sqList& L, int p, int x) {
    p--;//转化成下标
    if(p < 0 || p >= L.length) return false;
    L.data[p] = x;
    return false;
}

//查找第p个位置[1, length]上的数
int SearchByPos(sqList& L, int p) {
    p--;//转化成下标
    if(p < 0 || p >= L.length) return -1;
    return L.data[p];
}

//查找第1个出现x的位置
int SearchByVal(sqList& L, int x) {
    for(int i = 0; i < L.length; i++) {
        if(x == L.data[i]) return i;
    }
    return -1;
}

//输出顺序表
void print(sqList& L) {
    if(L.length == 0) puts("顺序表为空!");
    for(int i = 0; i < L.length; i++) {
        printf("%d%s", L.data[i], i==L.length-1?"\n":"->");
    }
}

int main() {
    
    sqList L;
    init(L);
    /*
    insert(L, 1, 3);
    insert(L, 1, 2);
    insert(L, 1, 1);
    print(L);
    insert(L, 4, 4);
    print(L);
    insert(L, 4, 100);
    print(L);
    */

    /*
    insert(L, 1, 3);
    insert(L, 1, 2);
    insert(L, 1, 1);
    printf("%d\n", SearchByVal(L, 1));
    */
    return 0;
}