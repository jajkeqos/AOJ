#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back

struct S{
  int w,h,l;

  S(int w, int h):w(w), h(h){
    l = w*w + h*h;
  }
};

bool operator<(const S& a, const S& b)
{
  // l、hの順番で優先順位を付けて比較
  return tie(a.l, a.h) < tie(b.l, b.h);
}

int main(){
  vector<S> rect;
  //それぞれの対角を計算して初期化
  for(int i = 1; i < 200; i++){
    for(int j = i + 1; j < 200; j++){
      rect.pb(S(j,i)); //w: j, h: i
    }
  }
  sort(rect.begin(), rect.end());

  int H, W;
  while(cin >> H >> W, H || W){
    S s = S(W,H);
    S t = *(++lower_bound(rect.begin(),rect.end(),s));
    /*
    for(int i = 0; i < rect.size(); i++){
      if(H == 1 && W == 8) cout << rect[i].l << endl;
      if(rect[i].l == s.l && rect[i+1].l != s.l){
       cout << rect[i+1].h << " " << rect[i+1].w << endl;
       break;
      }
    }*/
    cout << t.h << " " << t.w << endl;
  }
  return 0;
}
