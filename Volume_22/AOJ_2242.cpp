#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),b.end()

struct Era{
  string name;
  int begin,l;

  Era(string name, int begin, int l):name(name),begin(begin),l(l){}

};

int main(void){

  int N, Q;

  while(cin >> N >> Q, N || Q){
    vector<Era> v;
    int begin,l;
    string name;
    int n = N;
  
    while(N--){
      cin >> name >> l >> begin;
      v.pb(Era(name, begin-l+1, l));
    }
  
    while(Q--){
      bool flag = true;
      int query;
      cin >> query;

      rep(i,n){
        // cout << "Begin: " << v[i].begin  << " End: " << v[i].begin+v[i].l << endl;
        if(v[i].begin <= query && query < v[i].begin+v[i].l){
          flag = false;
          cout << v[i].name << " " << query - v[i].begin + 1 << endl;
        }
      }
      if(flag) cout << "Unknown" << endl;
    }
  }

  return 0;
}
