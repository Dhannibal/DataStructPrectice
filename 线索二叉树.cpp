#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    char ch;
    node *lch, *rch;
    bool lflag, rflag;
    node(char a) {
        ch = a;
    }
};
//中序遍历
void thRead(node *p, node *pre) {
    if(p == NULL) return;
    thRead(p->lch, pre);

    if(p->lch == NULL) {
        p->lflag = 1;
        p->lch = pre;
    }
    else p->lch = 0;
    if(pre->rch == NULL) {
        pre->rflag = 1;
        pre->rch = p;
    }
    else pre->rflag = 0;
    pre = p;
    
    cout<<p->ch<<endl;
    thRead(p->rch, pre);
}

int main() {
    node* A = new node('A');
    node* B = new node('B');
    node* C = new node('C');
    node* D = new node('D');
    node* E = new node('E');
    A->lch = B; A->rch = C;
    B->lch = D ;B->rch = E;
    thRead(A, A);
    return 0;
}