#include <bits/stdc++.h>
using namespace std;
int in=0;
void computelps(string b,int M,int* lps){
int len=0,i=1;
lps[0]=0;
while (i<M)
{
    if (b[i]==b[len])
    {
        len++;
        lps[i]=len;
        i++;
    }
    else
    {
         if (len!=0)
        {
            len=lps[len-1];
        }
        else
        {
            lps[i]=0;
            i++;
        }
    }
    
    
}

}
bool kmp(string a,string b)
{
    int M=b.size();
    int N=a.size();
    int lps[M];
    computelps(b,M,lps);
    int i=0,j=0;
    while (i<N and j<M)
    {
        if (a[i]==b[j])
        {
            i++;
            j++;
            if (j==M)
            {
                in=i-M;
                return 1;
            }
            
        }
        else if (i<N and a[i]!=b[j])
        {
             if(j!=0) j=lps[j-1];
            else i=i+1;
        }
        
        
    }
    return 0;
}
int main(){
        string a,b;
        cin>>a>>b;
        a+=a;
     bool t=kmp(a,b);
     if (t)
     {
        cout<<b.size()-in;
          
    }
     else
     {
        cout<<-1;
     }
     
}