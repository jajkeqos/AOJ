#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()
#define f first
#define s second
static const int dx[]={1,0,0,1,1,0,1, 1, 0,-1, 1, 1,-1};
static const int dy[]={0,1,0,1,0,1,1,-1, 1, 0, 1,-1, 1};
static const int dz[]={0,0,1,0,1,1,1, 0,-1, 1,-1, 1, 1};
P put[7*7*7];
int n, m, p;
int peg[7][7][7];

bool check(int x, int y, int z){
  for(int k = 0; k < 13; k++){
    int seq = 1;
    int nx = x;
    int ny = y;
    int nz = z;
    while(true){
      nx += dx[k];
      ny += dy[k];
      nz += dz[k];

      if(!(0 <= nx && nx < n && 0 <= ny && ny < n && 0 <= nz && nz < n)) break;
      if(peg[nx][ny][nz] == peg[x][y][z]) seq++;
      else break;
    }
    nx = x;
    ny = y;
    nz = z;

    while(true){
      nx -= dx[k];
      ny -= dy[k];
      nz -= dz[k];

      if(!(0 <= nx && nx < n && 0 <= ny && ny < n && 0 <= nz && nz < n)) break;
      if(peg[nx][ny][nz] == peg[x][y][z]) seq++;
      else break;
    }

    if(seq >= m) return true;
  }
  return false;
}

int solve(){
  fill((int *)peg, (int *)peg+7*7*7, -1);

  for(int i = 0; i < p; i++){
    int x = put[i].f;
    int y = put[i].s;
    bool canPut = false;
    bool win = false;
    for(int z = 0; z < n; z++){
      if(peg[x][y][z] == -1){
        peg[x][y][z] = i % 2;
        canPut = true;
        win = check(x,y,z);
        break;
      }
    }
    if(!canPut) break;
    if(win) return i+1;
  }
  return 0;
}

int main(void){

  while(cin >> n >> m >> p, n||m||p){
    for(int i = 0; i < p; i++){
      int x, y;
      cin >> x >> y;
      put[i].f = x - 1;
      put[i].s = y - 1;
    }
  
    int ans = solve();
  
    if(ans == 0) cout << "Draw" << endl;
    else if(ans%2) cout << "Black " << ans << endl;
    else cout << "White " << ans << endl;
  }

  return 0;
}
