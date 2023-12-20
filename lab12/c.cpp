#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 400;
bool RAIL[N + 1][N + 1];
int n, m, i, j, first;
int ddd[N + 1];
vector<int> gAir[N + 1],    gRail[N + 1];
queue<int> q;

int main() {
  for(int i = 2; i <= N; i++) ddd[i] = 2e9;
  cin >> n >> m;
  for(int _ = 0; _ < m; _++) {
    cin >> i >> j;
    gRail[i].push_back(j);
    gRail[j].push_back(i);
    RAIL[i][j] = RAIL[j][i] = 1;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i != j && !RAIL[i][j]) gAir[i].push_back(j);
    }
  }
  q.push(1);
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    for(auto u :    gRail[v]) {
      if(ddd[u] > ddd[v] + 1) {
        q.push(u);
        ddd[u] = ddd[v] + 1;
      }
    }
  }
  if(ddd[n] == 2e9) {
    cout << -1;
    return 0;
  }
  first = ddd[n];
  for(int i = 2; i <= N; i++) ddd[i] = 2e9;
  q.push(1);
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    for(auto u : gAir[v]) {
      if(ddd[u] > ddd[v] + 1) {
        q.push(u);
        ddd[u] = ddd[v] + 1;
      }
    }
  }
  if(ddd[n] == 2e9) {
    cout << -1;
    return 0;
  }
  cout << max(first, ddd[n]);
  return 0;
}