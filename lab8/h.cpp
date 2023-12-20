#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<string , int> mp;
    string st;
    for(int i=0;i<n;i++){
        cin>>st;
        for(int j=0;j<st.size();j++){
            string c="";
            for(int k=j;k<st.size();k++){
                c+=st[k];
                auto it2=mp.find(c);
                if(i==0){
                    mp[c]=0;
                }
                else if(it2!=mp.end() && it2->second==i-1){
                    mp[c]=i;
                }
            }
        }
    }
    int m=0;
    for(auto &it:mp){
        if(m<it.first.size() && it.second==n-1){
            m=it.first.size();
        }
    }
    for(auto &it:mp){
        if(it.first.size()==m && it.second==n-1){
            // cout<<ortak;
            cout<<it.first;
        }
        
    }
}