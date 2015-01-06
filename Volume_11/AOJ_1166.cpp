#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()
#define MP make_pair

int main(void){
  int w, h;
  while(cin >> w >> h, w || h){
    int maze[40][40][4]; // 0:左、1:下、2:右、3:上
    int cost[40][40] ={0};
    rep(i, 2*h-1){
    
      if(i%2){
        rep(j,w){
          int tmp;
          cin >> tmp;
          maze[i/2][j][1] = tmp; // 下を埋める
          maze[i/2+1][j][3] = tmp; // 下から見ると上を埋めた事にもなる
        }
      }else{
        rep(j,w-1){
          int tmp;
          cin >> tmp;
          maze[i/2][j][2] = tmp; // 右を埋める
          maze[i/2][j+1][0] = tmp; // 右から見ると左を埋めた事にもなる
        }
      }
    }
  
    // BFS
    queue<P> q;
    cost[0][0] = 1;
    q.push(MP(0,0));
    while(!q.empty()){
      int i = q.front().first;
      int j = q.front().second;
      q.pop();
      int cnt = cost[i][j];
      // 範囲内で到達可能で訪れていなかったら
      if((i < h-1) && (maze[i][j][1] == 0 ) && (cost[i+1][j] == 0)){
        q.push(MP(i+1,j));
        cost[i+1][j] = cnt + 1;
      }
      if((i > 0) && (maze[i][j][3] == 0 ) && (cost[i-1][j] == 0)){
        q.push(MP(i-1,j));
        cost[i-1][j] = cnt + 1;
      }
      if((j > 0) && (maze[i][j][0] == 0 ) && (cost[i][j-1] == 0)){
        q.push(MP(i,j-1));
        cost[i][j-1] = cnt + 1;
      }
      if((j < w-1) && (maze[i][j][2] == 0 ) && (cost[i][j+1] == 0)){
        q.push(MP(i,j+1));
        cost[i][j+1] = cnt + 1;
      }
    }
    
    cout << cost[h-1][w-1] << endl;
  }
  return 0;
}

