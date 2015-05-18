#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define inf INT_MAX/4
#define ALL(v) v.begin(),v.end()

int N, W;
int w[101];
int v[101];
// dp[個数][重さ] = 合計金額
int dp[101][10001];

void init(){
  rep(i,101) rep(j,10001) dp[i][j] = INT_MAX;
}

// i番目以降の品物から重さの総和がj以下となるように選ぶ
// 上から決めていく
int rec(int i, int j){
  // 全探索は再帰で書いたほうがよろしいらしい
  // 訪れたことがアレばその値を使う
  if(dp[i][j] != INT_MAX) return dp[i][j];

  int res;
  // すでにn 個とっていたら0を返す
  if(i == N){
    res = 0;
  }else if(j < w[i]){
    // 品物が入らなかったら次を試す
    res = rec(i+1,j);
  }else{
    // 入れない場合と入れる場合を試す
    // w[i]をいれたときの合計額にv[i]を足す　
    res = max(rec(i+1,j), rec(i+1,j-w[i])+v[i]);
  }

  return dp[i][j] = res;

}

int main(void){


  // Input
  cin >> N >> W;
  init();
  rep(i,N) cin >> v[i] >> w[i];

  cout << rec(0,W) << endl;

  return 0;
}
