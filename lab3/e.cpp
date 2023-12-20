#include <bits/stdc++.h>
using namespace std;
int n, k,x1,y,x2,y2,i;
int a[200001];
map<int, int> m;
map<int, int>::iterator it;
int bin_search(){
    int l=1,r=i-1,mid;
    while (l<=r)
    {
        mid=(l+r)/2;
        if(a[mid]==k) return mid;
        else if(a[mid]<k) l=mid+1;
        else r=mid;
        if (l==r)
        {
            return l;
        }
        
        
    }
    return mid;
}
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin>>n>>k;
for (int i = 0; i < n; i++)
{
    cin >> x1 >> y >> x2 >> y2;
    ++m[max(max(x1, y), max(x2, y2))]; 
}
for(it = m.begin(), i = 1; it != m.end(); it++, i++)a[i] = a[i - 1] + it->second;
it = m.begin();
n = bin_search() - 1;

while(n--) ++it;
cout << it->first;
return 0;
}