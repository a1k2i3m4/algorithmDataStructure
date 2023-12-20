#include <iostream>
#include <map>
using namespace std;
int main(){
int n;
cin>>n;
map<string ,string> m;
string last,first;
while (n--)
{
    cin>>first>>last;
    if(m.size()==0){
        m[first]=last;
    }
    else
    {
        bool t=1;
        for(map<string ,string >::iterator it =m.begin();it!=m.end();++it){
            if (m[it->first]==first)
            {
                m[it->first]=last;
                t=0;
                break;
            }
            
        }
        if(t==1){
            m[first]=last;
        }
    }
    
}
 cout<<m.size()<<endl;
    for(auto it:m){
        cout<<it.first<<" "<<it.second<<endl;
    }

}