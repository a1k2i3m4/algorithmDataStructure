#include <iostream>
#include <vector>
using namespace std;
void merge(vector<string> &a,int low,int high ,int mid){
int li,hi,bi;
string b[a.size()];
li=low;
hi=mid+1;
bi=low;
while (li<=mid && hi<=high)
{
    if(a[li].size()<=a[hi].size()){
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
void mergeSort(vector<string> &a,int low,int high ){
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
    cin>>ws;
    string s;
    while (n--)
    {
        getline(cin,s);
        vector<string> a;
        string t="";
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]!=' ') t+=s[i];
            else{ a.push_back(t); t="";}
            if(i==s.size()-1) a.push_back(t);
        }
        mergeSort(a,0,a.size()-1);
        for(int j=0;j<a.size();j++){
            cout<<a[j]<<" ";
        }
        cout<<endl;
    }
    
}