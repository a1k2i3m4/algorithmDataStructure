#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n, m, i, j, w, a, b, s, f, sssssss, sums;
int d[N + 1];
vector<pair<int, int>> g[N + 1];
queue<int> q;

bool BFS(int s, int f) {
  for(int i = 1; i <= N; i++) d[i] = 2e9;
  d[s] = 0;
  q.push(s);
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    for(auto p : g[v]) {
      int u = p.first, w = p.second;
      if(d[u] > d[v] + w) {
        q.push(u);
        d[u] = d[v] + w;
      }
    }
  }
  if(d[f] == 2e9) return false;
  sssssss += d[f];
  return true;
}

int main() {
  cin >> n >> m;
  for(int _ = 0; _ < m; _++) {
    cin >> i >> j >> w;
    g[i].push_back(make_pair(j, w));
    g[j].push_back(make_pair(i, w));
  }
  cin >> s >> a >> b >> f;
  if(BFS(s, a) && BFS(a, b) && BFS(b, f)) sums = sssssss;
  else sums = 2e9;
  sssssss = 0;
  if(BFS(s, b) && BFS(b, a) && BFS(a, f)) {}
  else sssssss = 2e9;
  sssssss = min(sssssss, sums);
  if(sssssss == 2e9) cout << -1;
  else cout << sssssss;
  return 0;
}