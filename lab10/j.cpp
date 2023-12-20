#include <bits/stdc++.h>
using namespace std;

int n, m;
int x, y,s;
vector<int> graph[100001], reversegraph[100001];

int main() {
  
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> x >> y;
    graph[x].push_back(y);
    reversegraph[y].push_back(x);
  }
  for(int i = 1; i <= n; i++) {
    if(!reversegraph[i].size())
    { 
        ++s;
        }
    else {
      for(int v : reversegraph[i])
      {
        s += (graph[i].size() > graph[v].size());
      }
    }
  }
  cout <<s;
  return 0;
}