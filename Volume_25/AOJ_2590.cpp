#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()

char base36(int x){
  if(0 <= x && x <= 9) return char(x+'0');
  x -= 10;
  return char(x+'A');
}

int main(void){

  int N,M,Q;
  while(cin >> N >> M >> Q, N||M||Q){
    vector<set<char> > bulb(M);
    vector<bool> on(N,false);

    // すべての可能性がある
    rep(i,M) rep(j,N) bulb[i].insert(base36(j));

    rep(i,Q){
      string S,B;
      cin >> S >> B;
      // スイッチがはいっていたら反転させる
      rep(j,N) if(S[j] == '1') on[j] = !on[j];
      rep(j,M){
        // スイッチの状態と矛盾しているものを消していく
        if(B[j] == '1'){
          rep(k,N) if(!on[k]) bulb[j].erase(base36(k));
        }else{
          rep(k,N) if(on[k]) bulb[j].erase(base36(k));
        }
      }
    }

    rep(i,M){
      if(bulb[i].size() == 1) cout << *bulb[i].begin();
      else cout << "?";
    }
    cout << endl;

  }

  return 0;
}
