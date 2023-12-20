#include <bits/stdc++.h>
using namespace std;

bool w[100001];
int n, m, x, y;
int start,finish;
vector<int> graph[100001];

void dfs(int v) {
  w[v] = true;
  for(int u : graph[v]) {
    if(!w[u]) dfs(u);
  }
}

int main() {
  cin >> n >> m;
  for(int _ = 0; _ < m; _++) {
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  cin >> start >> finish;
  dfs(start);
  if(!w[finish]) cout << "NO";
  else cout << "YES";
  return 0;
}