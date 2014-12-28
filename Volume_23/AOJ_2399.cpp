#include <iostream>
#include <vector>
using namespace std;

bool people[101][101];
int K[101];

int main(){

  int N;
  while(cin >> N, N){
    fill((bool *)people,(bool *)people+101*101,false);
    fill(K,K+101,false);
    for(int i = 0; i < N; i++){
      int m;
      cin >> m;
      for(int j = 0; j < m; j++){
        int tmp;
        cin >> tmp;
        people[i+1][tmp] = true; //i+1がtmpを知っている
      }
    }
    int k;
    cin >> k;
    vector<int> v;
    for(int i = 0; i < k; i++){
      cin >> K[i];
    }
    for(int i = 0; i < N; i++){
      bool flag = true;
      for(int j = 0; j < k; j++){
        if(!people[i+1][K[j]]) flag = false; //知らない時
      }
      if(flag) v.push_back(i+1);
    }
    if(v.size() == 1) cout << v[0] << endl;
    else cout << "-1" << endl;
  }
  return 0;
}
