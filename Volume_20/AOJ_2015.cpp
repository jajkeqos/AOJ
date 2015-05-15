#include <iostream>
using namespace std;

int main(){
  int N, M;
  while(1){
    cin >> N >> M;
    if(N == 0 && M == 0) break;
    int yoko[1600];
    int tate[1600];

    for(int i = 0; i < N; i++) cin >> tate[i];
    for(int i = 0; i < M; i++) cin >> yoko[i];

    int countWidth[1500010] = {0};

    for(int i = 0; i < M; i++){
      int sum = yoko[i];
      countWidth[sum] += 1;
      for(int j = i + 1; j < M; j++){
        sum += yoko[j];
        countWidth[sum]++;
      }
    }

    int ans = 0;

    for(int i = 0; i < N; i++){
      int sum = tate[i];
      ans += countWidth[sum];
      for(int j = i + 1; j < N; j++){
        sum += tate[j];
        ans += countWidth[sum];
      }
    }

    cout << ans << endl;
  }

}
