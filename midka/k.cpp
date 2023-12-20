#include <iostream>
#include <deque>
using namespace std;
int main(){
    int q;
    bool t=1;
    cin>>q;
    int a,x;
    deque<int> d;
    while(q--)
    { 
      cin>>a;
      if(a==1){
        cin>>x;
       if(t==1){
    
        d.push_back(x);
       }
       else
       {
        d.push_front(x);
       } 
      }
      else
      {
        if(t==1){
            t=0;
        }
        else
        {
            t=1;
        }
        
      }
    
      

    }
    while (d.size()!=0)
      {
        if (t==1)
        {
            cout<<d.front()<<" ";
            d.pop_front();
        }
        else
        {
            cout<<d.back()<<" ";
            d.pop_back();
        }
        
        
      }
}