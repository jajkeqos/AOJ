#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()

int main(void){

  int N, M;
  while(cin >> N >> M, N||M){
    vector<pair<int, pair<int, int> > > v;
    int m = M;
    while(m--){
      int t, s, d;
      cin >> t >> s >> d;
      v.pb(make_pair(t,make_pair(s,d)));
    }
    // 感染しているかどうか
    bool p[20001] = {false};
    p[1] = true;
    int ans = 1;
    sort(ALL(v));

    rep(i,M){
      // 送信元のコンピュータが感染していて送信先のコンピュータが感染していなかったら感染する
      if(p[v[i].second.first] && !p[v[i].second.second]){
        ans++;
        p[v[i].second.second] = true;
      }
    }

    cout << ans << endl;
  }

  return 0;
}
