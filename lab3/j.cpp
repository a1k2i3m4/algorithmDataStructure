#include <bits/stdc++.h>
using namespace std;
int n,h;
int a[200001];
bool chek(int target){
    int c=0;
for(int i=1;i<=n;i++) c+=(a[i]/target)+(a[i]%target>0);
return c<=h;

}
int bin_search(){
    int l=1,r=100000,mid;
    while (l<=r)
    {
        mid=l+(r-l)/2;
        if(chek(mid)) r=mid-1;
        else l=mid+1;
    }
    return l;
}
int main(){
    cin>>n>>h;
    for (int i =1; i <=n; i++)cin>>a[i];
     sort(a, a + n + 1);
   cout<<bin_search();
}