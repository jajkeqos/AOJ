#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 

int main(void){
  int n, m; // pc, student

  while(cin >> n >> m, n||m){
    vector<P> v[100001];
    int r;
    cin >> r;
    while(r--){
      int t, pc, mem, s; //time, pc, student, log(in|out)
      cin >> t >> pc >> mem >> s;
      v[mem].pb(P(t,s));
    }

    // 生徒ごとにソートする
    for(int i = 1; i <= m; i++) sort(v[i].begin(), v[i].end());

    int q;
    cin >> q;
    while(q--){
      int start, end, mem;
      cin >> start >> end >> mem;
      int time = start, cnt = 0, ans = 0;
      rep(i, v[mem].size()){
        P p = v[mem][i];

        if(time <= p.first && cnt > 0){
          ans += min(end, p.first) - time;
        }
        time = max(start , min(p.first,end));
        cnt += (p.second) ? 1 : -1;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
