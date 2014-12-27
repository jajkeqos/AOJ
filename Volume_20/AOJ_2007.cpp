#include <iostream>
using namespace std;

const int coin[] = {10,50,100,500};

int main(){
  int n;
  bool first = true;
  while(cin >> n, n){
    int money[4]; //所持金
    int change[4]; //お釣り
    cin >> money[0] >> money[1] >> money[2] >> money[3];
    n = money[0] * coin[0] + money[1] * coin[1] + money[2] * coin[2] + money[3] * coin[3] - n; //余計に支払った分
    fill(change,change+4,0);
    for(int i = 3; i >= 0; i--){ //余計に支払った分を最小枚数で払う
      change[i] = (int)(n / coin[i]);
      n -= change[i] * coin[i];
    }

    if(first){
      first = false;
    }else{
      cout << endl;
    }
    for(int i = 0; i < 4; i++){
      int ans = money[i] - change[i];
      if(ans > 0) cout << coin[i] << ' ' << ans << endl;
    }
  }
}
