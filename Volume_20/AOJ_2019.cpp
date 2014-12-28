#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

struct Prince{
  int d;
  int p;
  bool operator<(const Prince& right) const {
    return p == right.p ? d < right.d: p < right.p;
  }
};


int main(void){

  int yado, yosan;
  while(cin >> yado >> yosan, yado || yosan){
    vector<Prince> v;
    while(yado--){
      Prince tmp;
      cin >> tmp.d >> tmp.p; //距離、期待値
      v.push_back(tmp);
    }
    sort(v.rbegin(), v.rend());
    int res = 0;
    for(int i = 0; i < v.size(); i++){
      int money;
      if(yosan >= v[i].d) money = v[i].d; //予算が上回っている時
      else if(yosan != 0) money = yosan; //予算が足りない時はあるだけ
      else money = 0; //予算が無いとき
      // cout << "Money: " << money << endl;
      res += v[i].p * (v[i].d - money); //期待値 * (護衛を雇えなかった距離)
      // cout << "Res: " << res << endl;
      yosan -= money;
      // cout << "v[" << i << "]: (" << v[i].d << ", " << v[i].p << ")" << endl;
    }
    cout << res << endl;
  }
  return 0;
}
