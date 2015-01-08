#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()

int dat[12][7];
int cnt;

int dfs(int i, int j, int match){
  if(match == dat[i][j]){
    cnt++;
    dfs(i,j+1,match);
  }
  return cnt;
}

void out();

int main(void){
  int H;

  while(cin >> H, H){
    int ans = 0;
    rep(i,H) rep(j,5) cin >> dat[i][j];

    int judge = H;
    while(judge--){
      rep(i,H){
        int d1 = dat[i][0];
        int d2 = dat[i][1];
        int d3 = dat[i][2];
        int d4 = dat[i][3];
        int d5 = dat[i][4];
        if(d1 && d1 == d2 && d2 == d3 && d3 == d4 && d4 == d5){
          ans += d1 * 5;
          for(int j = 0; j <= 4; j++) dat[i][j] = 0;
        }else if(d1 && d1 == d2 && d2 == d3 && d3 == d4){
          ans += d1 * 4;
          for(int j = 0; j <= 3; j++) dat[i][j] = 0;
        }else if(d2 && d2 == d3 && d3 == d4 && d4 == d5){
          ans += d2 * 4;
          for(int j = 1; j <= 4; j++) dat[i][j] = 0;
        }else if(d1 && d1 == d2 && d2 == d3){
          ans += d1 * 3;
          for(int j = 0; j <= 2; j++) dat[i][j] = 0;
        }else if(d2 && d2 == d3 && d3 == d4){
          ans += d2 * 3;
          for(int j = 1; j <= 3; j++) dat[i][j] = 0;
        }else if(d3 && d3 == d4 && d4 == d5){
          ans += d3 * 3;
          for(int j = 2; j <= 4; j++) dat[i][j] = 0;
        }
      }

      // rep(i,H){
      //   rep(j,5){
      //     cout << dat[i][j] << " ";
      //   }
      //   cout << endl;
      // }
      //   cout << endl;
      for(int i = 0; i < H; i++){ //H回実行
        for(int j = H - 1; j > 0; j--){
          for(int k = 0; k < 5; k++){
            if(dat[j][k] == 0) swap(dat[j][k],dat[j-1][k]);
          }
        }
      }
    }

    cout << ans << endl;
  }


  return 0;
}
