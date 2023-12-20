#include <bits/stdc++.h>
 
using namespace std;
 
 
class disjoint_set_union {
    long long* parent;
    long long* rank;
 
public:
    disjoint_set_union(long long n)
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
 
    void u(long long e, long long y)
    {
        long long s1 = search(e);
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
 
class G {
    vector<vector<long long> > edgelist;
    long long V;
 
public:
    G(long long V) { this->V = V; }
 
    void addEdge(long long e, long long y, long long w)
    {
        edgelist.push_back({ w, e, y });
    }
 
    void kruskals_mst()
    {
        sort(edgelist.begin(), edgelist.end());
 
        disjoint_set_union s(V);
        long long otvet = 0;
        for (auto edge : edgelist) {
            long long w = edge[0];
            long long e = edge[1];
            long long y = edge[2];
 
            if (s.search(e) != s.search(y)) {
                s.u(e, y);
                otvet += w;
            }
        }
 
        cout << otvet;
    }
};
int n, ddddd[666][666], e[666];
bool was[666];
vector <int> otvet;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> ddddd[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        cin >> e[i];
    }
    for(int k = 1; k <= n; k++) {
        was[e[k]] = 1;
        int res = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                ddddd[i][j] = min(ddddd[i][j], ddddd[i][e[k]] + ddddd[e[k]][j]);
                if(was[i] && was[j]){
                    res = max(ddddd[i][j], res);
                }
            }
        }
        otvet.push_back(res);
    }
    for(auto i : otvet){
        cout << i << "\n";
    }
}