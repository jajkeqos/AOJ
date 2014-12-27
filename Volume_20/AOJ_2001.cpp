#include <iostream>
#include <algorithm>
using namespace std;
int amida[1001][101]; //高さ、縦線の数
int main(){

  int taten, yokon, target;

  while(cin >> taten >> yokon >> target, taten || yokon || target){
    int h, p, q;
    int targetH = -1; //targetの一番上の高さ
    fill((int *)amida, (int *)amida+1001*101, -1); //amidaを-1で初期化
    while(yokon--){ //横線を追加
      cin >> h >> p >> q;
      if(targetH < h) targetH = h;
      amida[h][p] = q; //pからqに行ける
      amida[h][q] = p; //qからpに行ける
    }
    //targetからしたまでたどっていく
    int now = target;
    for(int i = targetH; i > 0; i--){
      if(amida[i][now] != -1){ //横線があるとき
        now = amida[i][now];
      }
    }
    cout << now << endl;
  }
    return 0;
  }
