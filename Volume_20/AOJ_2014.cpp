#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()

static const int dx[] = {1,0,-1,0};
static const int dy[] = {0,1,0,-1};
int w, h;
char area[51][51];
bool white[51][51];
bool black[51][51];

void dfs(int x, int y, bool isVisit[51][51]){
  rep(i,4){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(0 <= nx && nx < w && 0 <= ny && ny < h){
      if(area[ny][nx] == '.' && !isVisit[ny][nx]){
        isVisit[ny][nx] = true;
        dfs(nx,ny,isVisit);
      }
    }
  }
}

int main(void){

  while(cin >> w >> h, w||h){
    fill((bool *)white,(bool *)white+51*51, false);
    fill((bool *)black,(bool *)black+51*51, false);
    // 入力
    rep(i,h) cin >> area[i];
    

    rep(i,h) rep(j,w){
      if(area[i][j] == 'W'){
        dfs(j,i,white);
      }else if(area[i][j] == 'B'){
        dfs(j,i,black);
      }
    }
    int bl = 0, wh = 0;

    rep(i,h) rep(j,w){
      if(black[i][j] && !white[i][j]) bl++;
      if(!black[i][j] && white[i][j]) wh++;
    }
    cout << bl << " " << wh << endl;
  }


  return 0;
}
