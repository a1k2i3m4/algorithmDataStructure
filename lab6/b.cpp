#include <iostream>
#include <string>
using namespace std;

int partition(int arr[],int s,int e)
{
    int pivot=arr[e];
    int i=s;
    for(int j=s;j<e;j++)
    {
        if(arr[j]<pivot){
          
         swap(arr[i],arr[j]);
          i++;
       
        }
    }
    swap(arr[i],arr[e]);
    return i;
}
void quickSort(int arr[],int s,int e){
if(s<e){
int t=partition(arr,s,e);
quickSort(arr,s,t-1);
quickSort(arr,t+1,e);
}
}
int main()
{
int n,m;
cin>>n>>m;
int a[n],b[m];
for(int i=0;i<n;i++) {
cin>>a[i];
}

for(int i=0;i<m;i++){
    cin>>b[i];
}

quickSort(a,0,n-1);
quickSort(b,0,m-1);
int t=1;
int s=0;
int *arr=new int[t];
for(int i=0;i<n;i++){
int l=s;
int r=m-1;
int mid;
while(l<r){
  mid=(l+r)/2;
  if(b[mid]<a[i]) l=mid+1;
  if(b[mid]>=a[i])  r=mid-1;
  }
if (b[l]==a[i])
{
  arr[t-1]=a[i];
  t++;
  s=l+1;  
}

}
  for(int i=0;i<t-1;i++){
        cout<<arr[i]<<" ";
    }
}
