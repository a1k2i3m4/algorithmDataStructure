#include <iostream>
using namespace std;
void computeLPS(string s){
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
     cout<<M-lps[M-1];   
}
int main(){
    // freopen("input.txt","r",stdin);
    string s;
    cin>>s;
    computeLPS(s);
}