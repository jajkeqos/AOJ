#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()
#define N 1000001
bool prime[N];

void make_prime(){ //primeが0だったら素数
  fill(prime,prime+N,true);
  prime[0] = prime[1] = false;

  for(int i = 2; i*i < N; i++){
    if(prime[i] == true){
      for(int j = 2*i; j < N; j+=i){
        prime[j] = false;
      }
    }
  }
}

int main(void){

  make_prime();

  int m,a,b;

  while(cin >> m >> a >> b, m||a||b){

    for(int i = m; i >= 0; i--){
      bool flag = false;
      for(int j = 2; j*j <= i; j++){
        // i,jが素数じゃなかったらスルー
        if(i%j != 0) continue;
        if(!prime[j] || !prime[i/j]) continue;

        // 条件を満たさなければスルー
        if((double)a/b > (double)j/(i/j)) continue;
        cout << j << " " << i/j << endl;
        flag = true;
        break;
      }
      if(flag) break;
    }
  }

  return 0;
}
