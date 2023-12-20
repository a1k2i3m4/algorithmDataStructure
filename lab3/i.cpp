#include <bits/stdc++.h>
using namespace std;
int n,x,a[100000];
bool bin_search(){
  int l=1,r=n,mid;
  while (l<=r)
  {
    mid=l+(r-l)/2;
    if(a[mid]==x) return true;
    else if(a[mid]<x) l=mid+1;
    else r=mid-1;
    
  }
  return false;
}
int main(){
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    cin>>x;
    sort(a,a+n+1);
    if(bin_search()) cout<<"Yes";
    else cout<<"No";
    
}