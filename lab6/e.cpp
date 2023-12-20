#include <iostream>
using namespace std;
int n,m;
int partition(int a[],int s,int e){
int pivot=a[e];
int i=s;
for (int j = s; j <e; j++)
{
    if(a[j]>pivot){
        swap(a[i],a[j]);
        i++;
    }
}
    swap(a[i],a[e]);
    return i;
}
void quickSort(int a[],int s,int e){
    if(s<e){
        int t=partition(a,s,e);
        quickSort(a,s,t-1);
        quickSort(a,t+1,e);
    }
}
int main()
{
    cin>>n>>m;
    int a[n][m];
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
        
    }
    int j=0;
    while(j<m){
        int b[n];
    for (int i = 0; i < n; i++)
    {

        b[i]=a[i][j];
    }
    quickSort(b,0,n-1);
    for (int i = 0; i < n; i++)
    {

        a[i][j]=b[i];
    }
    j++;
    }
     for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
