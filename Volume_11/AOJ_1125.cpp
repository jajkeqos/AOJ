#include <iostream>
using namespace std;

int N,W,H;
int yoko,tate;
int ans;
int map[100][100];

void init(){
  ans = 0;
  for(int i = 0;i < 100; i++){
    for(int j = 0;j < 100; j++){
      map[i][j] = 0;
    }
  }
}

int total(int x, int y){
  //x,y からyoko,tate分に含まれる1を数える
  int sum = 0;
  for(int i = x; i < x + yoko; i++){
    for(int j = y; j < y + tate; j++){
      if(map[i][j] == 1) sum++;
    }
  }
  return sum;
}

void output(){
  for(int i = 0;i < H; i++){
    for(int j = 0;j < W; j++){
      cout << map[i][j] << ' ';
    }
    cout << endl;
  }
}

int main(){
  while(cin >> N,N){
    cin >> W >> H;
    init();
    while(N--){
      int x,y;
      cin >> x >> y;
      map[x-1][y-1] = 1;
    }
    int ansx,ansy;
    //output();
    cin >> yoko >> tate;
    for(int x = 0; x <=W - yoko; x++){
      for(int y = 0; y <=H - tate; y++){
        int sum = total(x,y);
        if(ans < sum){
          ans = sum;
          ansx = x;
          ansy = y;
        }
      }
    }
    cout << ans << endl;
    // cout << "x: " << ansx << " y: " << ansy << endl;
  }
  return 0;
}
