#include <iostream>
using namespace std;
int n;
long long a[200001],pre;
void heapify_down(int v){
    int best = v;
    if(2*v<=n && a[2*v]>a[best]) best=2*v;
    if(2*v+1<=n && a[2*v+1]>a[best]) best=2*v+1;
    if(best!=v){
        swap(a[best],a[v]);
        heapify_down(best);
    }
}
void delete_max(){
    swap(a[1],a[n]);
    --n;
    heapify_down(1);
}
void heapify_up(int v){
    while (v!=1 && a[v/2]<a[v])
    {
        swap(a[v/2],a[v]);
        v=v/2;
    }
}
void push(int x){
    n++;
    a[n]=x;
    heapify_up(n);
}
void heap_sort(){
    for (int i = 0; i < n; i++)
    {
        heapify_up(i);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    heap_sort();
    while (n!=1)
    {
        pre=a[1];
        delete_max();
        pre=abs(pre-a[1]);
        delete_max();
        push(pre);

    }
    cout<<a[1];
    return 0;
}