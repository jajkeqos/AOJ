#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()
#define MAX 100005
#define NIL -1

struct Node{int p, r, l;};
Node T[MAX];
int n, D[MAX];

void output(int u){
  int i, c;
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].p << ", ";
  cout << "depth = " << D[u] << ", ";

  // 親がなければ根
  if(T[u].p == NIL) cout << "root, ";
  // 左がなければ葉
  else if(T[u].l == NIL) cout << "leaf, ";
  // それ以外は上にも下にも続いてる
  else cout << "internal node, ";

  cout << "[";
  
  for(i = 0, c = T[u].l; c != NIL; i++, c = T[c].r){
    // 最初以外は「, 」を出力する
    if(i) cout << ", "; // うまい
    // cは子の値
    cout << c;
  }
  cout << "]" << endl;
}

int dig(int u, int p){
  // uの深さをpにする
  D[u] = p;
  // 右側にも子があれば同じ深さにする
  if(T[u].r != NIL) dig(T[u].r, p);
  // 最も左の子には1つ深くする
  if(T[u].l != NIL) dig(T[u].l, p+1);
}

int main(void){

  int r;
  cin >> n;
  
  //初期化
  rep(i, n) T[i].p = T[i].r = T[i].l = NIL;

  rep(i,n){
    int v, d, l;
    // id と 子の数
    cin >> v >> d;
    rep(j,d){
      int c;
      cin >> c;
      // もしも最初だったら左に追加する
      if(j == 0) T[v].l = c;
      // 最初じゃなかったら右に追加する
      // 右側にどんどん追加されていく
      else T[l].r = c;
      l = c;
      // 親を設定する
      T[c].p = v;
    }
  }

  // てっぺんを見つける
  rep(i,n){
    if(T[i].p == NIL) r = i;
  }

  // 上から順番に深さを割り当てて行く
  dig(r,0);

  // id順に繰り返す
  rep(i,n) output(i);

  return 0;
}
