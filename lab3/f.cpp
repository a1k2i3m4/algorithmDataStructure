#include <bits/stdc++.h>
using namespace std;
int n, p, m, cnt;
int a[1000001], dp[1000001];
int bin_search(){
    int l=1,r=n,mid;
    while (l<=r)
    {
       mid=(r+l)/2;
       if(a[mid]>m){
        r=mid-1;
        if(a[r]<m) return r;
       }
       else if(a[mid] < m) {
      l = mid + 1;
      if(a[l] > m) return l - 1;
    }
    else {
      l = mid;
      if(a[l + 1] != m) return l;
    }
    if(a[r] == m) return r;
       
    }
    return mid;
}
int main(){
cin>>n;

for (int i = 1; i <= n; i++)
{
    cin>>a[i];
}
int x;
sort(a, a + n + 1);
for (int i =1 ; i<=n; i++)
{
    dp[i]=dp[i-1]+a[i];
}
cin>>p;
for(int _ = 0; _ < p; _++) {
    cin >> m;
    cnt = bin_search();
    cout << cnt << " " << dp[cnt] << "\n";
  }
}