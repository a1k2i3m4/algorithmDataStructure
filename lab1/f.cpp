#include <bits/stdc++.h>
using namespace std;
void prime(int r){
    bool a[10000];
    
    int b[1000+1],t=1;
    for(int i=0;i<=10000;i++){
        a[i]=true;
    }
    for (int p=2;p*p<=10000;p++){
        if(a[p]==true){
            for(int i=p*p;i<=10000;i+=p){
               a[i]=false;
            }
            
        }
    }
    for(int i=2;i<=600;i++){
        if(a[i]==true){
            b[t]=i;
            t++;
        }
    }
    cout<<b[r];
}
int main()
{
    int r;
    cin>>r;
    prime(r);
}