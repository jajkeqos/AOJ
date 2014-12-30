#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 

int n,k,s;
int dfs(int N, int cnt, int sum){
  if(cnt == k){
    // sとsumが一致したらカウントする
    if(sum == s) return 1;
    else return 0;
  }
  //nを超えているかsを超えていたら終了
  if(N > n || sum > s) return 0;

  int res = 0;

  for(int i = N + 1; i <= n; i++){
    res += dfs(i,cnt+1,sum+i);
  }

  return res;
}

int main(void){

  while(cin >> n >> k >> s, n||k||s){
    cout << dfs(0,0,0) << endl;
  }
  return 0;
}
