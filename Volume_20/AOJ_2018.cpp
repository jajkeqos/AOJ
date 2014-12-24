#include <iostream>
using namespace std;

int main(){
 int N,M,P;
 int total;
 int winner;
 while(cin >> N >> M >> P, N){
   total = 0;
   winner = 0;
  for(int i = 1; i <= N; i++){ //カウンタ変数を競技者の番号と一致させる
    int x;
    cin >> x;
    if(i == M) winner = x;
    total += x;
  }
  if(winner == 0) cout << 0 << endl;
  else cout << total*(100-P)/winner << endl;
 }

  return 0;
}
