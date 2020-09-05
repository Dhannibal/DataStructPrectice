#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int temp[maxn];

void mergeSort(int a[], int l, int r) {
    if(l >= r) return;
    int mid = (l+r)/2;
    mergeSort(a, l, mid);
    mergeSort(a,mid+1, r);
    int i = l, j = mid+1, p = l;
    while(i <= mid && j <= r){
        if(a[i] < a[j]) temp[p++] = a[i++];
        else temp[p++] = a[j++];
    }
    if(i <= mid) while(i <= mid) temp[p++] = a[i++];
    if(j <= r) while(j <= r) temp[p++] = a[j++];
    assert(p == r+1);
    for(int i = l;i <= r; i++) a[i] = temp[i];
}


int a[maxn] = {0, 101, 5, 7, 8, 1, 4, 100};
int main() {
    mergeSort(a, 1, 7);
    for(int i = 1; i <= 7; i++) {
        printf("%d%c", a[i], " \n"[i==7]);
    }
    return 0;
}