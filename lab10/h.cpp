#include <bits/stdc++.h>
using namespace std;

bool a[101][101];
int n, m,s;
char vertex;

void dfs(int i, int j) {
  if(!a[i][j]) return;
  a[i][j] = 0;
  dfs(i + 1, j);
  dfs(i - 1, j);
  dfs(i, j + 1);
  dfs(i, j - 1);
}

int main() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> vertex;
      a[i][j] = vertex - '0';
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
    //   if a[i][j]==1 is island, after that I delete neighbour
      if(a[i][j]) {
        ++s;
        dfs(i, j);
      }  
    }
  }
  cout <<s;
  return 0;
}
