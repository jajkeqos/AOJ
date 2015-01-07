#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf LLONG_MAX/2 
#define ALL(v) v.begin(),v.end()
#define f first
#define s second


string str[1010];
int main(void){

  int N;
  while(cin >> N, N){
    // 入力 
    rep(i,N) cin >> str[i];

    string prev = "99999999999";
    
    pair<ll,ll> p;
    p.f  = inf;
    p.s = -inf;
    bool none = false;

    // 判定
    rep(i,N){
      string now = str[i];
      bool isEven = i%2 ? true : false;

      bool isX = now == "x" ? true : false;

      if(isX){
        // xが連続している時 => none
        if(prev == "x"){none =true; break;}
        ll prevNum = stoll(prev);
        if(isEven){ //偶数の時
          p.s = max(p.s,prevNum+1);
        }else{ //奇数の時
          p.f = min(p.f,prevNum-1);
        }
      }else{
        ll nowNum = stoll(now);
        if(prev == "x"){
          if(isEven){ //偶数の時
            p.f = min(p.f,nowNum-1);
          }else{ //奇数の時
            p.s = max(p.s,nowNum+1);
          }
        }else{
          ll prevNum = stoll(prev);
          if(isEven){ //偶数の時
            if(prevNum > nowNum) none = true;
          }else{ //奇数の時
            if(prevNum < nowNum)none = true;
          }
        }
      }
      prev = str[i];
    }
     // cout << "p.f " << p.f << " p.s " << p.s << endl;
     // cout << none << endl;

    string ans;
    if(none || p.f < p.s) ans = "none";
    else if(p.f == p.s) ans = to_string(p.s);
    else ans = "ambiguous";
  
    cout << ans << endl;
  }


  return 0;
}
