#include <iostream>
using namespace std;
string s;
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
void quicksort(int l,int h){
if (l< h) {
        int pi = partition(l, h);    
        quicksort( l, pi - 1);
        quicksort( pi + 1, h);
    }
}

int main(){


cin>>s;

quicksort(0,s.size()-1);

cout<<s;
}

