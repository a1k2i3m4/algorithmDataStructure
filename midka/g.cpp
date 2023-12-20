#include <deque>
#include <iostream>
using namespace std;
deque<int> d;
int main (){
    long long n,t;
    cin>>n;
    
    for (int i = 0; i < n; i++)
    { 
     cin>>t;
     d.push_back(t);
     while(true)
     {
        if(d.front()==t){
            break;
        }
        else if(abs(d.front()-t)>3000)
        {
            d.pop_front();
        }
        else
        {
            break;
        }
    } 
    cout<<d.size()<<" ";
        
    }
    
    
    
}