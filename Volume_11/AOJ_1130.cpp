#include <iostream>
using namespace std;

int W,H,ans;
char map[21][21];
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0}; //上、下、右、左

void output(){
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
        cout << map[i][j] << ' ';
      }
      cout << endl;
    }
}

void dfs(int x, int y){
  ans++;
  map[y][x] = '#';
  // cout << "x: " << x << " y: " << y << endl;
  // output();
  for(int i = 0; i < 4; i++){
    int xx = x + dx[i], yy = y + dy[i];
    //範囲内かつ'.'のとき
    // cout << "xx: " << xx << " yy: " << yy << endl;

    if(0 <= xx && xx < W && 0 <= yy && yy < H && map[yy][xx] == '.') dfs(xx,yy);
  }
}

int main(){

  while(cin >> W >> H, W || H){
    ans = 0;
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
        cin >> map[i][j];
      }
    }
    // output();

    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
        if(map[i][j] == '@') dfs(j,i); //j => x, i => y
      }
    }
    cout << ans << endl;
  }

  return 0;
}
