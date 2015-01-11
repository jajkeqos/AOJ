#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()

int h,w;
int ans;
int senbei[11][10001];
bool flag[11];

int cnt(){
  int tmp,res = 0;

  rep(j,w){
    tmp = 0;
    // 1になっているせんべいの数を数える
    rep(i,h) if((flag[i] && !senbei[i][j]) || (!flag[i] && senbei[i][j])) tmp++;
  
    if(tmp < h - tmp) res += h - tmp;
    else res += tmp;
  }

  return res;
}

void solve(int i){
  int res;
  // 最後まで達した時
  if(i == h){
    res = cnt();
    ans = max(ans,res);
    return;
  }

  //裏返さない
  flag[i] = false;
  solve(i+1);

  //裏返す
  flag[i] = true;
  solve(i+1);

}

int main(void){

  while(cin >> h >> w, h||w){
    rep(i,h) rep(j,w) cin >> senbei[i][j];
    ans = 0;
    solve(0);
  
    cout << ans << endl;
  }

  return 0;
}
