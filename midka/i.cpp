#include <iostream>
#include <stack>
using namespace std;
string to_binary(long long n)
{
    string s="";
    while(n!=0){
        if(n%2==1){
            s=s+"1";
        }
        else
        {
            s=s+"0";
        }
        n=n/2;
    }
    return s;
}
int main (){
    long long q,n;
    cin>>q;
    while(q--){
        bool t=0;
        stack<char> st;
        cin>>n;
        string s=to_binary(n);
        for (int i = 0; i < s.size() / 2; i++){
             swap(s[i], s[s.size() - i - 1]);}
        for (int i = 0; i < s.size(); i++)
        {
            if(st.size()==0 and s[i]=='0'){
                cout<<"NO"<<endl;
                t=1;
                break;
            }
            else 
            {
              if (st.size()==0 or s[i]=='1')
              {
                st.push(s[i]);
              }
              if(st.top()=='1' and s[i]=='0'){
                st.pop();
              }
            }
        }
        if(st.size()==0 and t==0)
        {
            cout<<"YES"<<endl;
        }
        else if(st.size()!=0 and t==0)
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}