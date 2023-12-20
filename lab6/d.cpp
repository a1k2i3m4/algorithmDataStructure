#include <iostream>
using namespace std;
int n;
int a[1000][8];
int san1(int i)
{
 int t=a[i][4]*1000+a[i][5]*100+a[i][6]*10+a[i][7];
 return t;
}
int san2(int i){
int t=a[i][2]*10+a[i][3];
return t;
}
int san3(int i){
int t=a[i][0]*10+a[i][1];
return t;
}
int partition(int s,int e){
int pivot=san1(e);
int pivot1=san2(e);
int pivot2=san3(e);
int i=s;
for (int j = s; j < e; j++)
{
    if(san1(j)<pivot){
        swap(a[i],a[j]);
        i++;
    }
    else if (san1(j)==pivot)
    {
        if (san2(j)<pivot1)
        {
            swap(a[i],a[j]);
            i++;
        }
        else if (san2(j)==pivot1)
        {
            if(san3(j)<pivot2){
            swap(a[i],a[j]);
            i++;
            }
        }
         
    }
    
}
 swap(a[i],a[e]);
    return i;

}
void quickSort(int s,int e){
if(s<e)
{
  int t= partition(s,e);
  quickSort(s,t-1); 
  quickSort(t+1,e); 
}

}
int main(){
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        int t=0;
        for (int j = 0; j<s.size(); j++)
        {
            if (s[j]=='-') continue;
            else{
                a[i][t]=int(s[j])-48;
                t++;
            }
        }
    }
  
    quickSort(0,n-1);
      for(int i=0;i<n;i++){
        for(int j=0;j<8;j++){
            cout<<a[i][j];
            if(j==1 || j==3){
                cout<<"-";
            }
        }
        cout<<endl;
    }
}