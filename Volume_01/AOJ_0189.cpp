#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define inf INT_MAX/4
#define MAX_V 11

int n;
int d[MAX_V][MAX_V];
int V;


void init(){
  V = 0;
  rep(i,MAX_V){
    rep(j,MAX_V){
      if(i == j){
        d[i][j] = 0;
      }else{
        d[i][j] = inf;
      }
    }
  }
}

int main(void){

  while(1){
    cin >> n;
    if(n == 0) break;

    init();
    rep(i,n){
      int a, b, c;
      cin >> a >> b >> c;
      d[a][b] = c;
      d[b][a] = c;
      V = max(max(V,a),b);
    }
    V++;

    // Warshall-Floyd
    rep(k,V){
      rep(i,V){
        rep(j,V){
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }

    int city, cost = inf;
    rep(i,V){
      int cnt = 0;
      rep(j,V){
        cnt += d[i][j];
      }
      // cout << "City: " << i << " Cost: " << cnt << endl;
      if(cost > cnt){
        cost = cnt;
        city = i;
      }
    }

    cout << city << " " << cost << endl;
  }


  return 0;
}
