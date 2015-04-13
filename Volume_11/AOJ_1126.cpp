#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()


int W, H;
vector<string> dat;


void init(){
  dat.clear();
}

void input(){
  rep(i,H){
    string r;
    cin >> r;
    dat.pb(r);
  }
}


string maxString(const string s1, const string s2){
  if((int)s1.size() == (int)s2.size()){
    rep(i,s1.size()){
      if(s1[i] != s2[i]) return (s1[i] - '0' > s2[i] - '0') ? s1 : s2; 
    }
  }else{
    if((int)s1.size() > (int)s2.size()) return s1;
    else return s2;
  }
  return s1;
}

bool isNum(char c){
  if('0' <= c && c <= '9') return true;
  else return false;
}

void solve(){
  vector<vector<string> > dp(H, vector<string>(W,"*"));
  rep(y, H){
    rep(x, W){
      char now = dat[y][x];

      // 数字だったら処理する
      if(!isNum(now)) continue;
      dp[y][x] = now;

      // 左側が0でなく範囲内かつ未到達ではなかったら大きいほうで比較して更新
      if(x >= 1){
        string l = dp[y][x-1];
        if(l != "0" && l != "*") dp[y][x] = maxString(dp[y][x], l + now);
      }
      // 上側が0でなく範囲内かつ数字だったらどっちが大きいか比較して更新
      if(y >= 1){
        string u = dp[y-1][x];
        if(u != "0" && u != "*") dp[y][x] = maxString(dp[y][x], u + now);
      }
    }
  }

  string res = "*";

  rep(y, H){
    rep(x, W){
      res = maxString(res, dp[y][x]);
    }
  }

  cout << res << endl;

}

int main(void){

  while(cin >> W >> H && W && H){
    init();
    input();
    solve();
  }


  return 0;
}
