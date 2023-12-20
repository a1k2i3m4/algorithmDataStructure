#include <iostream>
#include <stack>
using namespace std;
int main(){
    int q,value;
    string s;
    cin>>q;
    stack<int> st;
    stack<int> max;
    while (q--)
    {
      cin>>s;
      if(s=="add"){
        cin>>value;
        st.push(value);
        if(max.size()==0){
            max.push(value);
        }
        if(value>max.top()){
            max.push(value);
        }
        else
        {
            max.push(max.top());
        }
        
      } 
      else if (s=="delete")
      {
        if(st.size()==0){
            cout<<"error"<<endl;
        }
        else
        {
            st.pop();
            max.pop();
        }
    }
     else if (s=="getcur")
     {
        if(st.size()==0){
           cout<<"error"<<endl;
        }
        else
        {
            cout<<st.top()<<endl;
        }
    }
    else
    {
        if(max.size()==0){
           cout<<"error"<<endl;
        }
        else
        {
            cout<<max.top()<<endl;
        }
        
    }
    
         
    }
    
}