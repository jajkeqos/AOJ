#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define inf INT_MAX
#define ALL(v) v.begin(),v.end()


int main(void){
  int n;
  while(cin >> n, n){
    int dp[(1<<n)];
    // アイテム
    int t[n][n+1];

    // Input
    for(int i = 0; i < n; i++){
      for(int j = 0; j <= n; j++){
        cin >> t[i][j];
      }
    }

    // Initialize
    for(int i = 0; i < (1<<n); i++){
      dp[i] = inf;
    }
    dp[0] = 0;

    for(int i = 0; i < (1<<n); i++){
      for(int j = 0; j < n; j++){
        // クリアしてたらスルー
        if( (i & (1<<j)) != 0) continue;
        // 何もアイテムを使わない
        dp[i+(1<<j)] = min(dp[i] + t[j][0], dp[i+(1<<j)]);
        for(int k = 0; k < n; k++){
          // アイテムがなかったらスルー
          if((i & (1<<k)) == 0) continue;
          dp[i+(1<<j)] = min(dp[i]+t[j][k+1], dp[i+(1<<j)]);
        }
      }
    }

    cout << dp[(1<<n)-1] << endl;
  }

  return 0;
}
