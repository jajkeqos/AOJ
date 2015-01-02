#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;

typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/2 
#define plus 100
#define N 600

bool map[N][N];
int minCost[N][N];
int turn, n;
int sx, sy;
const int dx[] = {1,1,0,-1,-1,0};
const int dy[] = {0,1,1,0,-1,-1};


struct State{
  int x,y;
  int turn;

  State(int x, int y, int turn):x(x),y(y),turn(turn){}
};


int bfs(){
  queue<State> q;
  q.push(State(sx,sy,0));
  fill((int *)minCost, (int *)minCost+N*N, inf);

  minCost[sx][sy] = 0;
  

  while(!q.empty()){
    State now = q.front(); q.pop();
    
    now.turn++;

    // ターンが上回っていたらスルー
    if(now.turn > turn) continue;
  
    rep(i,6){
      int nx = now.x + dx[i];
      int ny = now.y + dy[i];
    
      if(0 <= nx && nx < N && 0 <= ny && ny < N && map[nx][ny] != true){
        // 最小コストより大きかったらスルー
        if(minCost[nx][ny] <= now.turn) continue;
        minCost[nx][ny] = now.turn;
        // cout << "x: " << nx-plus << " y: " << ny-plus << endl;
        q.push(State(nx,ny,now.turn));
      }
    }
  }

  int ans = 0;

  // ターン内に到着できれば増やす
  rep(i,N) rep(j,N) if(minCost[i][j] != inf) ans++;
  
  return ans;

}

int main(void){

  while(cin >> turn >> n, turn || n){
    fill((bool *)map, (bool *)map+N*N, false);
    while(n--){
      int x, y;
      cin >> x >> y;
      x += plus;
      y += plus;
      map[x][y] = true;
    }
    cin >> sx >> sy;
    sx += plus;
    sy += plus;

  
    cout << bfs() << endl;
  }
  return 0;
}
