#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;

typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 

int toSec(int h, int m, int s){
  return 3600*h+60*m+s;
}

int main(void){
  int n;

  while(scanf("%d", &n), n != 0){
    vector<P> v;
    rep(i,n){
      int h, m, s;
      // 出発
      scanf("%d:%d:%d", &h, &m, &s);
      v.pb(P(toSec(h,m,s),1));
      // 到着
      scanf("%d:%d:%d", &h, &m, &s);
      v.pb(P(toSec(h,m,s),-1));
    }
    // rep(i,v.size()) cout << v[i].first << " ";
    // cout << endl << "Sorted" << endl;
    sort(v.begin(),v.end());
    // rep(i,v.size()) cout << v[i].first << " ";
    // cout << endl;
    int ans, train;
    ans = train = 0;

    for(int i = 0; i < v.size(); i++){
      train += v[i].second;
      ans = (ans < train) ? train : ans;
    }
    cout << ans << endl;
  }
  return 0;
}
