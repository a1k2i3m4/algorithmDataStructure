#include <bits/stdc++.h>
using namespace std;
#include <deque>
int main(){
deque <int>d;
int a;
char b;
cin>>b;
while (b!='!')
{

if (b=='+')
{
    cin>>a;
    d.push_front(a);
}
else if (b=='-')
{
    cin>>a;
    d.push_back(a);
}
if(b == '*'){
            if(d.empty()){
                cout << "error" << endl;
            }
            else if(d.size() == 1){
                cout << d.front()*2 << endl;
                d.pop_front();
            }
            else{
                cout << d.front()+d.back() << endl;
                d.pop_back();
                d.pop_front();
            }
        }
 cin>>b;
}
}