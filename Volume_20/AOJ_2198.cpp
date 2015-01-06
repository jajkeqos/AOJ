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

struct Farm{
  string name;
  double effect;
  Farm(string name, double effect):name(name),effect(effect){}
};

bool operator < (const Farm& a, const Farm& b){
  return tie(b.effect,a.name) < tie(a.effect,b.name);
}

int main(void){
  int n;

  while(cin >> n, n){
    vector<Farm> v;
    while(n--){
      string l;
      int p, a, b, c, d, e, f, s, m;
      cin >> l >> p >> a >> b >> c >> d >> e >> f >> s >> m;
      //cout << l << p << a << b << c << d << e << f << s << m;
      int income = (f*s) * m - p;
      int time = a + b + c + (d + e) * m;
      double effect = (double)income / time;
      v.pb(Farm(l,effect));
    }
    sort(v.begin(), v.end());
    rep(i,v.size()) cout << v[i].name << endl;
    cout << "#" << endl;
  }
  return 0;
}
