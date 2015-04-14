#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()

void solve(int n){
  vector<string> v;
  while(n--){
    string s;
    cin >> s;
    v.pb(s);
  }

  for(int i = 1; i < v.size(); i++){
    for(int j = 0; j < v[i].size(); j++){
      if(v[i][j] == '.'){
        if(v[i][j+1] != '.') v[i][j] = '+';
        else v[i][j] = ' ';
      }
    }
  }

  for(int i = v.size()-1; i > 0; i--){
    for(int j = 0; j < v[i].size(); j++){
      if(v[i][j] == '+' && v[i-1][j] == ' '){
        // +  だったら
        int cnt = 1;
        while(1){
          if(v[i-cnt][j] == '+') break;
          v[i-cnt][j] = '|';
          cnt++;
        }
      }
    }
  }
  rep(i,v.size()) cout << v[i] << endl;
}

int main(void){

  int n;
  while(cin >> n && n){
    solve(n);
  }


  return 0;
}
