#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &a,int low,int high ,int mid){
int li,hi,bi;
int b[a.size()];
li=low;
hi=mid+1;
bi=low;
while (li<=mid && hi<=high)
{
    if(a[li]<=a[hi]){
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
void mergeSort(vector<int> &a,int low,int high ){
int mid;
if (low<high)
{
        mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,high,mid);
}
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    vector<int> c(n+m);
    for(int i=0;i<n;i++){
        c[i]=a[i];
    }
    for(int i=n;i<m+n;i++){
        c[i]=b[i-n];
    }
    mergeSort(c,0,n+m-1);
    for(int i=0;i<n+m;i++){
        cout<<c[i]<<" ";
    }
}