#include <iostream>
using namespace std;
void computeLps(string b,int M , int* lps){
int len=0;
int i=1;
lps[0]=0;
while (i<M)
{
    if(b[i]==b[len]){
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
void kmp(string a,string b){
    int  N=a.size();
    int M=b.size();
    int lps[M];
    int sum=0;
    string s; 
    computeLps(b,M,lps);
    int i=0,j=0;
    while (i<N and j<M)
    {
        if(a[i]==b[j]){
            i++;j++;
            if (j==M)
            {
                sum++;
                int l=i-M+1;
                s+=to_string(l)+ " ";
                j=lps[j-1];
            }
            
        }
        else
        {
            if (j!=0)
            {
                j=lps[j-1];
            }
            else i++;
        }
        
    }
    cout<<sum<<endl<<s;
}
int main(){
  string a,b;
  cin>>a>>b;
  kmp(a,b);
}