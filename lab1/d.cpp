#include <bits/stdc++.h>
using namespace std;
const int Max=100000;
 struct st{
   char a[Max];
   int topi;
   st(){
    topi=-1;
   }
   char  top(){
    if (topi==-1){ return 0;}
    return a[topi];
   }
   void push(int x){
    topi++;
    a[topi]=x;
   }
   void pop(){
    if(topi!=-1){
        topi--;
    }
   }
   
};
int main(){
   string s;
   int t=0;
   cin>>s;
   st stack;
   for(int i=0;i<=s.size();i++){
    if(t==0){
        stack.push(s[i]);
        t++;
        
    }
    else if(stack.top()==s[i] && t!=0){
       stack.pop();
       t--;
    }
    else if(stack.top()!=s[i] ){
        stack.push(s[i]);
        t++;
    }

   }

   if(t-1==0){
     cout<<"YES";
   }
   else{
    cout<<"NO";
   }
 }