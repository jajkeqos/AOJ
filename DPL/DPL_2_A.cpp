#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define inf 1<<29
#define ALL(v) v.begin(),v.end()

int V, E;
int dp[1<<15][15];
int s[15], t[15], d[15];
int ans = inf;

int main(void){

  int G[15][15];
  fill(G[0],G[15],inf);


  // Input
  cin >> V >> E;
  for(int i = 0; i < E; i++){
    cin >> s[i] >> t[i] >> d[i];
    // グラフ構築
    G[s[i]][t[i]] = d[i];
  }


  for(int z = 0; z < V; z++){
    for(int i = 0; i < (1<<V); i++){
      for(int j = 0; j < V; j++){
        dp[i][j] = inf;
      }
    }
    const int start = z;
    dp[(1<<start)][start] = 0;
    rep(j,(1<<V)){
      rep(k, V){
        if(dp[j][k] == inf) continue;
        rep(l, V){
          if(j & (1<<l)) continue;
          if(G[k][l] == inf) continue;
          dp[j | (1<<l)][l] = min(dp[j|(1<<l)][l], dp[j][k]+G[k][l]);
        }
      }
    }
    rep(i, V){
      ans = min(dp[(1<<V)-1][i]+G[i][start], ans);
    }
  }

  if(ans == inf) cout << -1 << endl;
  else cout << ans << endl;

  return 0;
}
