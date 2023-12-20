#include <iostream>
#include <algorithm>
using namespace std;

int n, f;
int a[100001];
bool chek(int c){
int flights=0;
for(int i=1;i<=n;i++) flights+=(a[i]/c)+(a[i]%c>0);
return flights<=f;
}
int bin_search(){
int l=1,r=10000,mid;
while (l<=r)
{
    mid=l+(r-l)/2;
    if(chek(mid)) r=mid-1;
    else l=mid+1;
}
return l;
}
int main(){
    cin>>n>>f;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n+1);
    cout<<bin_search();
    return 0; 
}