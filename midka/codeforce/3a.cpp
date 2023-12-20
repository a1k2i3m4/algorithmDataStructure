#include <iostream>
using namespace std;
int main()
{
    int q,x;
    int n;
    int t1,t2;
    cin>>q;
    while (q--)
    {
        cin>>n;
        for (int i = 1; i <=n; i++)
        {
            cin>>x;
            if(x==1){
                t1=i;
            }
            if(x==n){
                t2=i;
            }
        }
        
    }
    
}