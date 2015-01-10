#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()

static const int dx[] = {1,0,-1,0};
static const int dy[] = {0,-1,0,1};

int H,W;
char dat[110][110];

void dfs(int x, int y, char fruit){
  dat[y][x] = '.';

  rep(i,4){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(0 <= nx  && nx < W && 0 <= ny  && ny < H && dat[ny][nx] == fruit){
      // cout << "Erase " << "x: " << nx << " y: " << ny << endl;
      dfs(nx,ny,fruit);
    }
  }

}

int main(void){

  while(cin >> H >> W, H||W){
    int cnt = 0;
    rep(i,H) cin >> dat[i];

    rep(i,H){
      rep(j,W){
        if(dat[i][j] != '.'){
          dfs(j,i,dat[i][j]);
          cnt++;
        }
      }
    }
  
    // rep(i,H){
    //   rep(j,W){
    //    cout << dat[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    cout << cnt << endl;
  }


  return 0;
}
