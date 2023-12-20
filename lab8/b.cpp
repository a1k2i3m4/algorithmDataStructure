#include <string.h>

#include <iostream>
using namespace std;
int cnt = 0;
void check(string pat, string s1, string s2,int q){
    int M = pat.size();
    int N1 = s1.size();
    int N2 = s2.size();
    int N = min(N1, N2);
    int i, j;
    int p = 0;
    int t1 = 0;
    int t2 = 0;
    int h = 1;
    for(i=0;i<M-1;i++){
        h = (h*256)%q;
    }                         
    for(i =0;i<M;i++){
        p = (256 * p + pat[i]) % q;
        t1 = (256 * t1 + s1[i]) % q;
        t2 = (256 * t2 + s2[i]) % q;
    }
    for (i = 0; i <= N - M; i++) {
    if (p == t1 && p == t2) {
      cnt++;
    }
    if (i < N - M) {
      t1 = (256 * (t1 - s1[i] * h) + s1[i + M]) % q;
            t2 = (256 * (t2 - s2[i] * h) + s2[i + M]) % q;
            if (t1 < 0) t1 += q;
      if (t2 < 0) t2 += q;
    }
  }
}

int main(){
    string s1;string s2;
    cin >> s1 >> s2;
    string word; cin >> word;
    int q = 13;
    check(word,s1,s2, q);
    cout << cnt;
}