#include <iostream>
using namespace std;
long long a[2000001],n;
void hepify_up(int v){
    while(v!=1 and a[v/2]<a[v]){
        swap(a[v/2],a[v]);
        v=v/2;
    }
}
void heap_sort(){
    for (int i = 1; i <=n; i++)
    {
        hepify_up(i);
    }
}
void check(long long n){
    int s=0;
    for (int i = n; i>=1; i--)
    {
      if(a[2*i]<a[2*i+1]){
        s++;
      }
    }
    cout<<s;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        cin>>a[i];
    }
    heap_sort();
    if(n%2==1){
      check(n/2);
    }else
    {
        check(n/2-1);  
    }
    
}