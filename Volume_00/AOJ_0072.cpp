#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define inf INT_MAX
#define MAX_V 101

int n, m;
int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];

int prim(){
  // init
  rep(i,n){
    mincost[i] = inf;
    used[i] = false;
  }

  mincost[0] = 0;
  int res = 0;

  while(1){
    int  v = -1;
    // search min cost
    rep(u,n){
      // unused and
      if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
    }

    if(v == -1) break;

    used[v]  = true;
    res += mincost[v];

    rep(u,n){
      mincost[u] = min(mincost[u],cost[v][u]);
    }
  }
  return res;
}

int main(void){

  while(1){
    cin >> n;
    if(n == 0) break;
    cin >> m;
    rep(i,n) rep(j,n) cost[i][j] = inf;
    rep(i,m){
      int a,b,c;
      scanf("%d,%d,%d", &a, &b, &c);
      cost[a][b] = c/100-1;
      cost[b][a] = c/100-1;
    }
    cout << prim() << endl;
  }

  return 0;
}
