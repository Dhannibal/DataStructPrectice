const int maxn = 1e5+5;
typedef struct{
    int data[maxn];
    int length;
}sqList;

void init(sqList& L) {
    L.length = 0;
}
//第p个位置[1, length+1]
bool inisert(sqList& L, int p, int x) {
    p--;//转化成下标
    if(p < 0 || p > L.length) return false;
    if(L.length == p) {
        L.data[p] = x;
    }
    else {

    }
    L.length++;
    return true;
}


int main() {
    sqList L;

    return 0;
}