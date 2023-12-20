#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        bool r = false;
    for(int j = i-1; j >= 0; j--){
        if(a[i] >= a[j]){
            cout << a[j] << " ";
            r = true;
            break;
            }
        }
        if(!r) {
            cout << -1 << " ";
        }
    }
    return 0;
}   