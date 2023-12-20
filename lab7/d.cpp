#include <iostream>
#include <map>
#include <iomanip>
using namespace std;
int partition(double a[],string c[], string b[],int s,int e){
double pivot=a[e];
string pivotl=b[e];
string pivotf=c[e];
int i=s;
for (int j = s; j <e; j++)
{
    if (a[j]<pivot)
    {
        swap(a[i],a[j]);
        swap(b[i],b[j]);
        swap(c[i],c[j]);
        i++;
    }
    else if (a[j]==pivot)
    {
        if(b[j]<pivotl){
           swap(a[i],a[j]);
        swap(b[i],b[j]);
        swap(c[i],c[j]);
        i++;
        }
        else if (b[j]==pivotl)
       {
           if(c[j]<pivotf){
           swap(a[i],a[j]);
            swap(b[i],b[j]);
            swap(c[i],c[j]);
            i++;
        }
       }
    }
    
}
swap(a[i],a[e]);
swap(b[e],b[i]);
swap(c[i],c[e]);
return i;

}
void quickSort(double a[],string c[],string b[],int s,int e){
if(s<e){
    int t=partition(a,c,b,s,e);
    quickSort(a,c,b,s,t-1);
    quickSort(a,c,b,t+1,e);
}
}
int main(){
map<string,double> mp;
mp["A+"]=4;
mp["A"]=3.75;
mp["B+"]=3.50;
mp["B"]=3.00;
mp["C+"]=2.50;
mp["C"]=2.00;
mp["D+"]=1.5;
mp["D"]=1.00;
mp["F"]=0;
double t,credit;
int n;
cin>>n;
string fname[n],lname[n];
double m[n];
string a,b,s;
for (int i = 0; i < n; i++)
{
    cin>>a>>b;

    cin>>t;
    double total_credit=0;
    double sum=0;
    for (int j = 0; j < t; j++)
    {
        cin>>s;
        cin>>credit;
        total_credit+=credit;
        sum+=mp[s]*credit;
    }
    m[i]=sum/total_credit;
    fname[i]=b;
    lname[i]=a;
}
quickSort(m,fname,lname,0,n-1);
for (int i = 0; i < n; i++)
{
    cout<<lname[i]<<" "<<fname[i]<<" "<<setiosflags(ios::fixed)<<setprecision(3)<<m[i]<<endl;
}


}