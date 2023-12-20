#include <iostream>
#include <vector>
using namespace std;

int main(){
long long  n, s = 0;
cin >> n;

for(int i = 2; i <= n; i++){
        if(n % i == 0){
            s++;
            while(n % i == 0){
                n=n/i;
            }
        }
}

    cout << s;
}