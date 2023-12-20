#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,len;
int a[1002][1002];
queue<pair<int, int>> mario;
void check(int i, int j) {
  if(a[i + 1][j] == 1) {
    a[i + 1][j] = 2;
    mario.push(make_pair(i + 1, j));
  }
  if(a[i - 1][j] == 1) {
    a[i - 1][j] = 2;
    mario.push(make_pair(i - 1, j));
  }
  if(a[i][j + 1] == 1) {
    a[i][j + 1] = 2;
    mario.push(make_pair(i, j + 1));
  }
  if(a[i][j - 1] == 1) {
    a[i][j - 1] = 2;
    mario.push(make_pair(i, j - 1));
  }
}
bool checked(int i,int j){
    return !a[i + 1][j] && !a[i - 1][j] && !a[i][j + 1] && !a[i][j - 1];
}
bool checkSoloMushroom(){
for (int i = 1; i <=n; i++)
{
    for (int j = 1; j <= m; j++)
    {
        if (a[i][j]==1 and checked(i,j))
        {
            return true;
        }
        
    }
}
return false;
}
int main(){
cin>>n>>m;
for (int i = 1; i <=n; i++)
{
    for (int j = 1; j <= m; j++)
    {
        cin>>a[i][j];
        if (a[i][j]==2)
        {
            mario.push(make_pair(i,j));
        }
    }
}
if(checkSoloMushroom()){
cout<<-1;
return 0;
}
while (!mario.empty())
{
    len = mario.size();
    for(int _ = 0; _ < len; _++) {
      int i = mario.front().first, j = mario.front().second;
      mario.pop();
      check(i, j);
    }
    ++cnt;
}
if(cnt) cout << cnt - 1;
  else cout << 0;
  return 0;
}