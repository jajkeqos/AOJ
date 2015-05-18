#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define inf INT_MAX/4
#define ALL(v) v.begin(),v.end()

int dp[50001];

void init(){
  rep(i, 50001) dp[i] = INT_MAX;
}

int main(void){

  int n, m;
  int coin[21];
  init();
  // Input
  cin >> n >> m;
  rep(i, n) cin >> coin[i];

  dp[0] = 0;

  for(int i = 0; i <= n; i++){
    for(int j = 0; j < m; j++){
      int c = coin[j];
      if(i+c <= n) dp[i+c] = min(dp[i+c], dp[i]+1);
    }
  }

  cout << dp[n] << endl;

  return 0;
}
