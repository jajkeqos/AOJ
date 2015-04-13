#include <iostream>
#include <vector>
#include <climits>
using namespace std;

static const int MAX = 1000100;

int main(void){
  vector<int> allShimentai(MAX,INT_MAX);
  vector<int> oddShimentai(MAX,INT_MAX);


  allShimentai[0] = 0;
  oddShimentai[0] = 0;

  // すべての正四面体数と奇数だけの正四面体数を用意する
  // MAXまで正四面体数を計算する　奇数のときには奇数のやつにもpushする
  for(int i = 1; i < MAX; i++){
    for(int j = 1; j*(j+1)*(j+2)/6 <= i; j++){
      int tmp = j*(j+1)*(j+2)/6;
      // すべて試していく
      // 今までの最小と現在の結果の最小を取る min(a[必要な数-今の正四面体数]+1, 今のまでの最小)
      allShimentai[i] = min(allShimentai[i], allShimentai[i-tmp]+1);
      if(tmp % 2 == 1){
        oddShimentai[i] = min(oddShimentai[i], oddShimentai[i-tmp]+1);
      }
    }
  }

  int n;
  while(cin >> n && n){
    cout << allShimentai[n] << " " << oddShimentai[n] << endl;
  }

  return 0;
}

