#include <iostream>
using namespace std;
int computeLPS(string s){
int M=s.size();
int len=0;
int lps[M];
lps[0]=0;
int i=1;
while (i<M)
{
    if (s[i]==s[len])
    {
        len++;
        lps[i]=len;
        i++;
    }else
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

  return  lps[M-1];
}
int main(){
int n;
cin>>n;
while (n--)
{
    string s;
    cin>>s;
    int t;cin>>t;
    int k=computeLPS(s);
    int period=s.size()-k;
    int sum=s.size();
    for (int i = 1; i <t ; i++)
    {
        sum+=period;
    }
    cout<<sum<<endl;
}


}