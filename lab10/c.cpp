#include <bits/stdc++.h>
using namespace std;
// hjfhj
const int N=10000;
int a, b;
int depth[N + 1], path[N + 1];
vector<int> p,graph[N+1];
queue<int> q;
int main(){
    for (int i = 1; i <=N; i++)
    {
        depth[i]=2*1000000000;
        path[i]=-1;
    }
    cin>>a>>b;
    for (int i = 1; i <=N; i++)
    {
        if(i * 2 <= N){
        graph[i].push_back(i * 2);
        }
        if(i - 1 > 0){ 
        graph[i].push_back(i - 1);
        }
    }
    q.push(a);
    depth[a]=0;
    while (!q.empty())
    {
        int v=q.front();
        q.pop();
        for(auto u : graph[v]) {
      if(depth[v] + 1 < depth[u] && u < N + 1) {
        q.push(u);
        depth[u] = depth[v] + 1;
        path[u] = v;
      }
    }
    }
    cout <<endl<< depth[b] << "\n";
  for(int v = b; v != -1; v = path[v]) p.push_back(v);
  for(int i = p.size() - 2; i >= 0; i--) cout << p[i] << " ";
  return 0;

}