#include <bits/stdc++.h>
using namespace std;
string str(string& s ){
    int in=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!='#'){
            s[in]=s[i];
            in++;
        }
        else if(s[i]=='#' && in>=0){
            in--;
        }
        if (in<0){
            in=0;}
    }
    return s.substr(0,in);
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    
    if(str(s1)==str(s2)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}