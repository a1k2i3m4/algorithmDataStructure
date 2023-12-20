#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool p;
bool was[101];
int n, s, e;
int d[101];
vector<int> q, g[101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> p;
      if(p){ 
      g[i].push_back(j);
      }
    }
  }
  cin>>s>>e;
  was[s]=1;
  q.push_back(s);
  while (!q.empty())
  {
    int vertex=q.front();
    q.pop_back();
    for (int i:g[vertex])
    {
        if (!was[i])
        {
            was[i]=1;
            q.push_back(i);
            d[i]=d[vertex]+1;
        }
        
    }
    
  }
   if(!was[e]) cout << -1;
  else cout << d[e];
  return 0;

} 