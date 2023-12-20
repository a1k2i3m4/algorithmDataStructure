#include <iostream>
#include <vector>
using namespace std;
void merge(int a[],int low,int high ,int mid,int n){
int li,hi,bi;
int b[n];
li=low;
hi=mid+1;
bi=low;
while (li<=mid && hi<=high)
{
    if(a[li]<a[hi]){
        b[bi]=a[li];
        bi++;
        li++;
    }else
    {
        b[bi]=a[hi];
        bi++;
        hi++;
    }
}
while (li<=mid)
{
    b[bi]=a[li];
    bi++;
    li++;
}
while (hi<=high)
{
    b[bi]=a[hi];
    hi++;
    bi++;
}
for(int i=low;i<bi;i++){
        a[i]=b[i];
    }

}
void mergeSort( int a[],int low,int high,int n ){
int mid;
if (low<high)
{
        mid=(low+high)/2;
        mergeSort(a,low,mid,n);
        mergeSort(a,mid+1,high,n);
        merge(a,low,high,mid,n);
}
}
int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a[i]=x;
    }
    
    int b[m];
    for (int i = 0; i < m; i++)
    {
        int x;
        cin>>x;
        b[i]=x;
    }
    mergeSort(a,0,n-1,n);
    mergeSort(b,0,m-1,m);
    int start=0;
    for (int i = 0; i < n; i++)
    {
        int s=start;
        int e=m-1;
        int mid;
        while (s<=e)
        {
            mid=(s+e)/2;
            if(b[mid]>=a[i]){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
         if(b[s]==a[i]){
            cout<<a[i]<<" ";
            start=s+1;
        }
    }
    
}