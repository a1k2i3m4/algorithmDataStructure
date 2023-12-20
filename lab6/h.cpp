#include <iostream>
using namespace std;
int partition(char a[],int s,int e){
    char pivot= a[e];
    int i=0;
    for (int j = s; j < e; j++)
    {
        if (a[j]<pivot)
        {
            swap(a[i],a[j]);
            i++;
        }
        
    }
    swap(a[i],a[e]);
    return i;
    
}
void quickSort(char a[],int s,int e){
    if(s<e){
        int t=partition(a,s,e);
        quickSort(a,s,t-1);
        quickSort(a,t+1,e);
    }
}
int main(){
    int n;
    cin>>n;
    char a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    quickSort(a,0,n-1);
    char s;
    cin>>s;
    if(s>=a[n-1]){
        cout<<a[0];
    }
    else
    {
        int st=0;
        int e=n-1;
        bool ok=1;
        while (st<e)
        {
            int mid=(st+e)/2;
            if(a[mid]<s){
                st=mid+1;
            }
            if(a[mid]>s) 
            e=mid-1;
            else{
                st=mid;
                ok=0;
                break;
            }
        }
        if(ok){
            cout<<a[st];
        }
        else cout<<a[st+1];
    }
    
}