#include <iostream>
using namespace std;
int n;
bool p[100001];
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin>>n;
for (int i = 2; i < 100000; i++)
{
    p[i]=true;
}
for (int i = 2; i*i <=n; i++)
{
    if(p[i]){
    for (int j = i*i; j <= n; j+=i)
    {
        p[j]=false;
    }
    }
}
int i = 2;
while(true){
    if (p[i] and p[n-i])
    {
        break;
    }
    
}
cout << i << " " << n - i;
return 0;


}