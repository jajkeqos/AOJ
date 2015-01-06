#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()

int n;

int dfs(int sum, int d, int cnt){
  // 合計値とNが一致したらカウント
  if(sum == n) return 1;
  // 4つ以上使ってしまったらカウントしない
  if(cnt >= 4) return 0;
  int res = 0;
  
  for(int i = d; i*i <= n; i++){
    if(sum + i*i > n) break;
    res += dfs(sum+i*i,i,cnt+1);
  }

  return res;
}

int main(void){

  while(cin >> n, n){
  
    cout << dfs(0,1,0) << endl;
  
  }

  return 0;
}
