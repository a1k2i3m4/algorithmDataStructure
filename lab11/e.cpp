#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<int> gr;
int dsu_get(int v) {
	if (v == gr[v]) {
		return v;
	}
	return gr[v] = dsu_get(gr[v]);
}

bool dsu_unite(int a, int b) {
	a = dsu_get(a);
	b = dsu_get(b);
	if (a != b) {
        gr[a] = b;
        return true;
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    gr.resize(n);
    a.resize(n);
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        gr[i]=i;
    }
    unordered_set<int> s;
    vector<int> res;
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        res.push_back(cnt);
        cnt++;
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]>i && dsu_unite(i,a[i][j])){
                cnt--;
            }
        }
    }
    reverse(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}