#include <bits/stdc++.h>
using namespace std;
void computeLps(string s,int M,int* lps){
int len=0;
lps[0]=0;
int i=1;
while (i<M)
{
    if (s[i]==s[len])
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
bool  kmp(string a,string b,int* lps)
{
    int M = b.size();
    int N = a.size();
    int i=0,j=0;
    while ((N-i)>=(M-j))
    {
        if (a[i]==b[j])
        { 
            i++;
            j++;
        
        if (j==M)
        {
            return 1;

        }
        }
        else if (i<N && a[i]!=b[j])
        {
            if(j!=0) j=lps[j-1];
            else i=i+1;
        }
        
    }
    return false;
}
int main()
{
    string a,b;
    cin>>a>>b;
    int lps[b.size()];
    computeLps(b,b.size(),lps);
    string newA="";
    int t;
    if(a.size()<b.size()){
     t=b.size()/a.size()+1;
    }
    else t=0;
    while(t!=0){
        t--;
     newA+=a;
    }
    bool r=kmp(newA,b,lps);
    if (r)
    {
        cout<<newA.size()/a.size();
    
    }
    else
    {
        newA+=a;
        bool p=kmp(newA,b,lps); 
        if (p==1)
         {
        cout<<newA.size()/a.size();
         }
        else
       {
        cout<<-1;
       }
    
    }
    
}