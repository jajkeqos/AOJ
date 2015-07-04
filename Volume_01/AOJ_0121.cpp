#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define inf INT_MAX / 4
#define ALL(v) v.begin(), v.end()
#define func [&]

const int dx[4] = {1, -1, 4, -4};

int main(void) {
  map<string, int> cost;
  string s = "01234567";

  queue<string> q;
  q.push(s);
  cost[s] = 0;

  // !emptyより楽
  while (q.size()) {
    string now = q.front();
    q.pop();
    int pos = now.find("0");
    rep(i, 4) {
      int nextPos = dx[i] + pos;
      if (0 > nextPos || nextPos > 7) continue;
      // 右端と左端を交換しないように
      if (pos == 3 && nextPos == 4 || pos == 4 && nextPos == 3) continue;
      string next = now;
      swap(next[pos], next[nextPos]);
      // 遷移してたら無視
      if (cost.find(next) != cost.end()) continue;
      q.push(next);
      cost[next] = cost[now] + 1;
    }
  }

  string in = "";
  while (getline(cin, in)) {
    string res = "";
    // 空白を削除する
    rep(i, in.size()) {
      if (in[i] != ' ') res.pb(in[i]);
    }
    cout << cost[res] << endl;
  }

  return 0;
}
