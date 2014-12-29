#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 10000000
int prime[N];
vector<int> v;
vector<int>::iterator pos;

void make_prime(){ //primeが0だったら素数
  fill(prime,prime+N,0);
  prime[0] = prime[1] = 1;

  for(int i = 2; i*i < N; i++){
    if(prime[i] == 0){
      for(int j = 2*i; j < N; j+=i){
        prime[j] = 1;
      }
    }
  }

  for(int i = 0; i < N; i++){
    if(prime[i] == 0) v.push_back(i);
  }
}

int main(){
  make_prime();
  int k;
  while(cin >> k, k){
    pos = lower_bound(v.begin(),v.end(),k); //kと同じかそれ以上の素数を探す
    if(k == *pos){ //kが素数だった時
      cout << 0 << endl;
    }else{
      //int afterPrime = v[distance(v.begin(),pos)];
      //int beforePrime = v[distance(v.begin(),pos)-1];
      //cout << afterPrime - beforePrime << endl;
      cout << *pos - *(--pos) << endl;
    }
  }
  return 0;
}

