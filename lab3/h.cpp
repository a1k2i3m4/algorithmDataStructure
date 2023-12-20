#include <bits/stdc++.h>
using namespace std;
int n,m,dp[200001];
int bin_search(int mistake){
  int l=1,r=n,mid;
  while (l<=r)
  {
    mid=l+(r-l)/2;
    if(dp[mid] == mistake) return mid;
    else if(dp[mid]<mistake) l=mid+1;
    else  r=mid;
    if(l==r) return l;
    }
  return mid ;
  }
int main(){
    ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    cin>>n>>m;
    for (int i = 1; i <=n; i++)
    {
        cin>>dp[i];
        dp[i]=dp[i-1]+dp[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int x;cin>>x;
        cout<<bin_search(x)<<endl;
    }
    
}