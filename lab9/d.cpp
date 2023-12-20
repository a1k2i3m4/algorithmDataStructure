#include <iostream>
#include <vector>
using namespace std;
int computeLps(string s){
int len=0;
int M=s.size();
int lps[M];
lps[0]=0;
int i=1;
int max=0;
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
 return lps[M-1];
}
int main(){
string text;
cin>>text;
text[0]=tolower(text[0]);
int n;
cin>>n;
int max=0;
vector<pair<string,int>> v(n);
for (int i = 0; i < n; i++)
{
    string g;
    cin>>g;
    v[i].first=g;
    g[0]=tolower(g[0]);
    string str=g+"."+text;
    int t=computeLps(str);
    if (max<t)
    {
        max=t;
    }
    v[i].second=t;
}
int cnt=0;
  if(max==0){
        cout<<0;
        return 0;
    }
for(auto x:v){
    if (max==x.second)
    {
        cnt++;
    }
}
cout<<cnt<<endl;
for (auto x:v)
{
    if (x.second==max)
    {
        cout<<x.first<<endl;
    }
    
}

}