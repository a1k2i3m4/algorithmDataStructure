#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    int n;
    cin>>n;
    vector<long long> a;
    for (int i = 0; i < n; i++)
    {
      long long  x;
      cin>>x;
      a.push_back(x);
    }
sort(a.begin(),a.end());
    long long l=0;
    long long r=n-1;
    while (l<r)
    {
        if (a[l]+a[r]==t)
        {
            if(a[l]<a[r]){
            cout<<a[l]<<" "<<a[r];
            }
            else
            {
                cout<<a[r]<<" "<<a[l];
            }
            
            break;
        }
        else if(a[l]+a[r]>t){
            r--;
        }
        else
        {
            l++;
        }
        
    }
    
   
}