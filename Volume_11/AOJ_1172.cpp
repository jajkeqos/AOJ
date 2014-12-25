#include <iostream>
#include <algorithm>
using namespace std;

#define N 1234567*2+1
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

  int main(void){
    int n;
    make_prime();
    while(cin >> n, n){
      int cnt = 0;
      for(int i = n+1; i <= n*2; i++){
        if(isPrime[i]) cnt++;
      }
      cout << cnt << endl;
    }
    return 0;
  }
