#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int prime[1000001];

void make_prime(){ //primeが0だったら素数
  fill(prime,prime+1000001,0);
  prime[0] = prime[1] = 1;

  for(int i = 2; i*i < 1000001; i++){
    if(prime[i] == 0){
      for(int j = 2*i; j < 1000001; j+=i){
        prime[j] = 1;
      }
    }
  }
}

int main(void){
  int n,p;
  make_prime();

  while(cin >> n >> p){
    vector<int> ans;
    vector<int> num;
    ans.clear();
    num.clear();
    if(n == -1 && p == -1) break;
    for(int i = n + 1; i < n + p + 1000; i++){ //nより大きいものだけ調べる
      if(prime[i] == 0) num.push_back(i); //n素数だったらnumに突っ込む
    }
    //numにはnより大きい素数が入っている
    for(int i = 0; i < num.size(); i++){
      for(int j = i; j < num.size(); j++){
        ans.push_back(num[i]+num[j]); //素数を足していく
      }
    }
    sort(ans.begin(), ans.end());
    cout << ans[p-1] << endl;
  }
  return 0;
}
