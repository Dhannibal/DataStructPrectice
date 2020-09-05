#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;

void adjust(int a[], int p, int len){
    while(2*p <= len){
        int j = 2*p;
        if(j+1<= len && a[j+1] > a[j]) j++;
        if(a[j] > a[p]) {
            swap(a[p], a[j]);
            p = j;
        }
        else break;
    }
}


void print(int a[]) {
    for(int i = 1; i <=7; i++) {
        printf("%d%c", a[i], " \n"[i==7]);
    }
}

void heapSort(int a[], int len) {
    for(int i = len/2; i >= 1; i--) {
        int j = 2*i;
        if(j+1 <=len && a[j+1] > a[j])j++;
        swap(a[i], a[j]);
        adjust(a, j, len);
    }
    for(int i = len; i  >= 2; i--) {
        printf("%d ", a[1]);
        swap(a[i], a[1]);
        adjust(a, 1, i-1);
    }
    printf("%d\n", a[1]);
}


int a[maxn] = {0, 101, 5, 7, 8, 1, 4, 100};
int main() {
    heapSort(a, 7);
    return 0;
}
