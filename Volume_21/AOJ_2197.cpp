#include <iostream>
using namespace std;

int N;

int main(void){
  while(cin >> N && N){
    int cnt = 0, l = 1, r = 2;
    int sum = l + r;
    while( r < N ){ //右側がNに届いたら終了
      if(sum < N){ //合計がより小さかったら右側に広げる
        r++;
        sum += r;
      }else if(sum > N){ //合計のほうが大きかったら左側を狭める
        sum -= l;
        l++;
      }else{ //Nと合計が一致したら回数を増やす
        cnt++;
        r++;
        sum += r;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
