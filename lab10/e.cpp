#include <bits/stdc++.h>
using namespace std;

int n, query;
int  x, y, z;
bool a[1001][1001];

bool checkAll() {
  return a[x][y] && a[y][z] && a[x][z];
}

int main() {
  cin >> n >> query;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++){ 
        cin >> a[i][j];
    }
  }
  for(int i = 0; i < query; i++) {
    cin >> x >> y >> z;
    if(checkAll()) cout << "YES";
    else cout << "NO";
    cout <<endl;
  }
  return 0;
}