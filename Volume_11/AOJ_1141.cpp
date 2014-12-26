#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define N 10000000

bool isPrime[N];

void make_prime(){
  fill(isPrime,isPrime+N, true);
  isPrime[0] = isPrime[1] = false; //初期化
  for(int i = 0; i < N; i++){
    if(!isPrime[i]) continue; //isPrimeがfalseだったらスルー
      for(int j = 2; i*j < N; j++){ //iの倍数をfalseにしていく
        isPrime[i*j] = false;
      }
    }
  }

int main(){
  int n, a, d;
  make_prime();
  while(cin >> a >> d >> n, a || d || n){
    int cnt = 0, i = 0;
    while(1){
      if(isPrime[a+i*d]){
       cnt++;
       if(cnt == n){
         cout << a+i*d << endl;
         break;
       }
      }
      i++;
    }
    // cout << cnt << endl;
  }
  return 0;
}
