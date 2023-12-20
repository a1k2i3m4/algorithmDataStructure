#include <bits/stdc++.h>
using namespace std;
void computelps(string s,int M,int* lps){
int len=0,i=1;
lps[0]=0;
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
void kmp(string s,string text,int n){
   int M=s.size();
   int ans=0;
   int N=text.size();
   int lps[M];
   computelps(s,M,lps);
   int i=0,j=0;
   while (i<N and j<M)
   {
       if (s[j]==text[i])
       {
        i++;j++;
        if (j==M)
        {
            ans++;
            j=lps[j-1];
            if (ans==n)
            {
                cout<<"YES";
                return;
            }
            
        }
        }
        else if (i<N && text[i]!=s[j])
        {
            if(j!=0) j=lps[j-1];
            else i=i+1;
        }
        
       
   }
   cout<<"NO";
}
int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    string text;
    cin>>text;
   kmp(s,text,n);
}