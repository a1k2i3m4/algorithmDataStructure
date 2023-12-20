#include<iostream>
#include <vector>
using namespace std;
int n,q;
int  p,x;
int a[100001];
void heapify_d(int  v){
    int best=v;
    if (2*v<=n and a[2*v]>a[v]) best=2*v;
    if(2*v+1<=n and a[2*v+1]>a[v]) best=2*v+1;
    if(best!=v){
        swap(a[v],a[best]);
        heapify_d(best);
    }
}
void heapify_u(int  v){
while(v!=1 and a[v/2]<a[v] ){
    swap(a[v],a[v/2]);
    v=v/2;
}

}
void heapify_u1(int  v){
while(v!=1 and a[v/2]<a[v] ){
    swap(a[v],a[v/2]);
    v=v/2;
}
cout<<v<<endl;
}
int main(){
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
        heapify_u(i);
    }
   cin>>q;
   while(q--){
    cin>>p>>x;
    a[p]+=x;
    heapify_u1(p);
   }
   for (int  i = 1; i <=n; i++)
   {
    cout<<a[i]<<" ";
   }
   
}