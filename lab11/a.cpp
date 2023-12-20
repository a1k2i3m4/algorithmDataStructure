#include <bits/stdc++.h>
using namespace std;
 
class dsu {
    long long* parent;
    long long* rank;
 
public:
    dsu(long long n)
    {
        parent = new long long[n];
        rank = new long long[n];
 
        for (long long i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
 
    long long search(long long i)
    {
        if (parent[i] == -1)
            return i;
 
        return parent[i] = search(parent[i]);
    }
 
    void unite(long long x, long long y)
    {
        long long s1 = search(x);
        long long s2 = search(y);
 
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};
 
class graph {
    vector<vector<long long> > edgelist;
    long long V;
 
public:
    graph(long long V) { this->V = V; }
 
    void pushEdge(long long x, long long y, long long w)
    {
        edgelist.push_back({ w, x, y });
    }
 
    void kruskalsMST()
    {
        sort(edgelist.begin(), edgelist.end());
 
        dsu s(V);
        long long ans = 0;
        for (auto edge : edgelist) {
            long long w = edge[0];
            long long x = edge[1];
            long long y = edge[2];
 
            if (s.search(x) != s.search(y)) {
                s.unite(x, y);
                ans += w;
            }
        }
 
        cout << ans;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> gr;
    int cnt = 2;
    int x,y,w;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        gr.push_back({w,{x,y}});
    }
    long long sum = 0;
    sort(gr.begin(),gr.end());
    while(cnt<=n){
        for(int i=0;i<gr.size();i++){
            int x = gr[i].second.first;
            int y = gr[i].second.second;
            int w = gr[i].first;
            if(x < cnt && cnt <= y){
                sum += w;
                cnt++;
                break;
            }
        }
    }
    cout << sum;
    return 0;
}