#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;

int findMid(int a[], int l, int r) {
    int p = a[l];
    while(l < r) {
        while(l < r && a[r] >= p) r--;
        a[l] = a[r];
        while(l < r && a[l] <= p) l++;
        a[r] = a[l];
    }
    a[l] = p;
    return l;
}

void quickSort(int a[], int l, int r) {
    if(l >= r) return;
    int pav = a[1];
    int pos =findMid(a, l, r);
    quickSort(a, l, pos-1);
    quickSort(a, pos+1, r);
}


int a[maxn] = {0, 101, 5, 7, 8, 1, 4, 100};
int main() {
    quickSort(a, 1, 7);
    for(int i = 1; i <= 7; i++) {
        printf("%d%c", a[i], " \n"[i==7]);
    }
    return 0;
}
