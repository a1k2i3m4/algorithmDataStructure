#include <iostream>
#include <vector>
using namespace std;
int n;
long long difMin=10000000;
vector<long long> a;
int partion(int s,int e){
long long  pivot=a[e];
int i=s;
for (int j = s; j< e; j++)
{
    if(abs(a[e]-a[j])<difMin) difMin=abs(a[e]-a[j]);
    if(a[j]<a[e]){
       
        swap(a[i],a[j]);
        i++;
    }
}
swap(a[i],a[e]);
return i;

}
void quickSort(int s,int e){
if(s<e){
    int t=partion(s,e);
   
    quickSort(s,t-1);
    quickSort(t+1,e);
}
}
int main()
{
 cin>>n;
    for (int i = 0; i <n; i++)
    {
        long long x;
        cin>>x;
        a.push_back(x);
    }
    quickSort(0,n-1);
     for (int i = 0; i <n; i++)
    {
       if(abs(a[i]-a[i+1])==difMin and i+1<n){
        cout<<a[i]<<" "<<a[i+1]<<" ";
       }
    }
    
    
}