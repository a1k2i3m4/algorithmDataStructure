#include <iostream>
using namespace std;
int n, m, _n;
long long mix;
long long a[1000001];
void heapify_down(int v){
    int best = v;
    if(2*v<=n && a[2*v]<a[best]) best=2*v;
    if(2*v+1<=n && a[2*v+1]<a[best]) best=2*v+1;
    if(best!=v){
        swap(a[best],a[v]);
        heapify_down(best);
    }
}
void pop_min(){
    swap(a[1],a[n]);
    --n;
    heapify_down(1);
}
int get_min(){
    return a[1];
}
void heapify_up(int v){
    while (v!=1 && a[v/2]>a[v])
    {
        swap(a[v/2],a[v]);
        v=v/2;


    }
}
void push(long long x){
    n++;
    a[n]=x;
    heapify_up(n);
}
void heap_sort(){
    for (int i = 1; i <= n; i++)
    {
        heapify_up(i);
    }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  _n=n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  heap_sort();
  while (m>get_min() && n>1)
  {
    mix = get_min();
    pop_min();
    mix+=2*get_min();
    pop_min();
    push(mix);
  }
  if(a[1]<m ) cout<<-1;
  else
  {
    cout<<_n-n;
  }
  
return 0;
}