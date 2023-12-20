#include <iostream>
#include <map>
using namespace std;
map<char,int> mp;
string s;
bool t=0;
int partition(int l,int h){
char pivot=s[h];
int i=l;
for (int j= l; j<h; j++)
{
    if (s[j]<s[h])
    {
        swap(s[i],s[j]);
        i++;
    }
}
    swap(s[i],s[h]);

    return i;
    
}
int partitionVowel(int l,int h){
char pivot=s[h];
t=0;
if (mp[s[h]]>=1)
{
    t=1;
}

int i=l;
for (int j= l; j<h; j++)
{
    if (mp[s[j]]>=1)
    {
        swap(s[i],s[j]);
        i++;
    }
}  
    swap(s[i],s[h]);
 
    return i;
    
}
void quicksort(int l,int h){
if (l< h) {
        int pi = partition(l, h);    
        quicksort( l, pi - 1);
        quicksort( pi + 1, h);
    }
}

int main(){

mp['a']=1;
mp['e']=2;
mp['i']=3;
mp['o']=4;
mp['u']=5;
int n;
cin>>n;
cin>>s;
int i =partitionVowel(0,n-1);
if(t==1){
quicksort(0,i);
quicksort(i+1,n-1);
}
else
{
    quicksort(0,i-1);
    quicksort(i,n-1);
}

cout<<s;
}

