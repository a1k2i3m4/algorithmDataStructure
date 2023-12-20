#include <bits/stdc++.h>
using namespace std;

int find(int a[],int x,int l,int r){
int m=l+(r-l)/2;
if(l>r) return -1;

    if(a[m] == x) return m;
    else if(a[m] < x) return find(a, x, m+1, r);
    else return find(a, x, l, m-1);
}
int dfind(int a[],int x,int l,int r){
    int m=l+(r-l)/2;
    if(l>r) return -1;
    if(a[m] == x) return m;
    else if(a[m] > x) return dfind(a, x, m+1, r);
    else return dfind(a, x, l, m-1);
}
int main(){
int t;cin>>t;
int a[t];
for (int i = 0; i < t; i++)
{
    cin>>a[i];
}
int n,m;
cin >> n >> m;
    int b[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    
    }
int k=0;
  while (true){
     if(k==t){
        break;
     }
     bool f=false;
      for(int i = 0; i < n; i++){
            int temp;
            if(i % 2 == 0) temp = dfind(b[i], a[k], 0, m-1);
            else temp = find(b[i], a[k], 0, m-1);
            if(temp != -1){
                f = true;
                cout << i <<  " " << temp;
                break;
            }
        }
      if(!f){
            cout << -1;
        }
        k++;
        cout << endl;
  }
  return 0;
}