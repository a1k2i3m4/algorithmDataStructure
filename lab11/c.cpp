#include <bits/stdc++.h>
using namespace std;
 
class dsu {
    int* parent;
    int* rank;
 
public:
 dsu(int n)
    {
        parent = new int[n];
        rank = new int[n];
 
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
 
    long long search(int i)
    {
        if (parent[i] == -1)
            return i;
 
        return parent[i] = search(parent[i]);
    }
 
    void Unite(int x, int y)
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
 
class Graph {
    vector<vector<int> > edgelist;
    int V;
 
public:
    Graph(int V) { this->V = V; }
 
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({ w, x, y });
    }
 
    void kruskalsMST()
    {
        sort(edgelist.begin(), edgelist.end());
 
     dsu s(V);
        long long ans = 0;
        for (auto edge : edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
 
            if (s.search(x) != s.search(y)) {
                s.Unite(x, y);
                ans += w;
            }
        }
 
        cout << ans;
    }
};
 
int main(){
    long long n,m;
    cin>>n>>m;
    long long x,y;
    cin>>x>>y;
    Graph g(n);
    string s;
    int w,u,l;
    for(long long i=0;i<m;i++){
        cin>>s>>w>>u>>l;
        long long c=0;
        if(s == "both"){
            c=min(x,y)*l;
        }
        else if(s == "big"){
            c = x*l;
        }else{
            c = y*l;
        }
        g.addEdge(w,u,c);
        //cout<<w<<" "<<u<<" "<<c<<endl;
    }
    g.kruskalsMST();
    return 0;
}