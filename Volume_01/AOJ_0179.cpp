#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define inf INT_MAX/4
#define ALL(v) v.begin(),v.end()

struct State{

  string str;
  int cnt;

};



vector<string> combi(const string str){
  vector<string> v;

  for(int i = 0; i < str.size(); i++){
    if(str[i] != str[i+1]){
      // blue
      if((str[i] == 'r' && str[i+1] == 'g') || (str[i+1] == 'r' && str[i] == 'g')){
        string next = str;
        next[i] = 'b';
        next[i+1] = 'b';
        v.pb(next);
      }
      // green
      if((str[i] == 'b' && str[i+1] == 'r') || (str[i+1] == 'b' && str[i] == 'r')){
        string next = str;
        next[i] = 'g';
        next[i+1] = 'g';
        v.pb(next);
      }
      // red
      if((str[i] == 'b' && str[i+1] == 'g') || (str[i+1] == 'b' && str[i] == 'g')){
        string next = str;
        next[i] = 'r';
        next[i+1] = 'r';
        v.pb(next);
      }
    }

  }

  return v;

}

bool isAllEquall(string str){
  bool flag = true;

  for(int i = 0; i < str.size()-1; i++){
    if(str[i] != str[i+1]){
      flag = false;
      break;
    }
  }

  return flag;
}

int main(void){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  while(1){
    cin >> s;
    if(s == "0") break;
    map<string, bool> isVisit;

    queue<State> q;
    q.push((State){s,0});
    bool flag = true;

    while(!q.empty()){
      State now = q.front();q.pop();
      string str = now.str;
      int cnt = now.cnt;
      if(isAllEquall(str)){
        flag = false;
        cout << cnt << endl;
        break;
      }

      if(isVisit.find(str) != isVisit.end()) continue;
      isVisit[str] = true;

      vector<string> v;

      v = combi(str);

      for(int i = 0; i < v.size(); i++){
        State next = {v[i], cnt+1};
        q.push(next);
      }

    }

    if(flag) cout << "NA" << endl;

  }


  return 0;
}
