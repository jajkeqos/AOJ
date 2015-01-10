#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()

int boal[11];

bool dfs(int cnt, int l, int r){
  if(cnt == 10) return true;

  bool res = false;
  // 左に入れる
  if(l < boal[cnt]){
    res = dfs(cnt+1,boal[cnt],r);
  }
  // 右に入れる
  if(r < boal[cnt]){
    res = dfs(cnt+1,l,boal[cnt]);
  }

  return res;
}

int main(void){

  int n;
  while(cin >> n){
    while(n--){
      rep(i,10) cin >> boal[i];
      rep(i,10) cout << boal[i] << " ";
    
      cout << (dfs(0,0,0) ? "YES" : "NO") << endl;
    }
  }


  return 0;
}
