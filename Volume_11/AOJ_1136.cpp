#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define inf INT_MAX/4
#define ALL(v) v.begin(),v.end()
#define MAXC 51

struct Point{
  int x,y;
  double d(const Point &p){
    return abs(x-p.x)+abs(y-p.y);
  }
};

int N, M[MAXC];
vector<Point> lines[MAXC];

void zurasu(vector<Point> &p){
  // ずらす分のxとy
  int diffx = p[0].x;
  int diffy = p[0].y;

  // ずらす分のxとyを求めるy
  for(int i = 1; i < p.size(); i++){
    if(p[i].x < diffx) diffx = p[i].x;
    if(p[i].y < diffy) diffy = p[i].y;
  }

  // すべてずらす
  for(int i = 0; i < p.size(); i++){
    p[i].x = p[i].x - diffx;
    p[i].y = p[i].y - diffy;
  }
}

void kaiten(vector<Point> &p){

  // 横幅を求める
  int diff = -inf*2;
  for(int i = 0; i < p.size(); i++){
    if(p[i].x > diff) diff = p[i].x;
  }

  // 90度回転
  for(int i = 0; i < p.size(); i++){
    const int x = p[i].x;
    const int y = p[i].y;
    // cout  << "oldx: " << x << " oldy: " << y << endl;
    p[i].x = y;
    p[i].y = diff - x;
    // cout  << "x: " << p[i].x << " y: " << p[i].y << endl;
  }
}

bool eq(vector<Point> &l1, vector<Point> &l2){
  bool flag = true;
  // 90 度回転
  kaiten(l2);
  for(int i = 0; i < l1.size(); i++){
    if(l1[i].x != l2[i].x || l1[i].y != l2[i].y){
      flag = false;
      break;
    }
  }
  if(flag) return true;
  // 180 度回転
  flag = true;
  kaiten(l2);
  for(int i = 0; i < l1.size(); i++){
    if(l1[i].x != l2[i].x || l1[i].y != l2[i].y){
      flag = false;
      break;
    }
  }
  if(flag) return true;
  // 270 度回転
  flag = true;
  kaiten(l2);
  for(int i = 0; i < l1.size(); i++){
    if(l1[i].x != l2[i].x || l1[i].y != l2[i].y){
      flag = false;
      break;
    }
  }
  if(flag) return true;
  // 360 度回転
  flag = true;
  kaiten(l2);
  for(int i = 0; i < l1.size(); i++){
    if(l1[i].x != l2[i].x || l1[i].y != l2[i].y){
      flag = false;
      break;
    }
  }
  if(flag) return true;


  reverse(l2.begin(), l2.end());
  flag = true;
  kaiten(l2);
  for(int i = 0; i < l1.size(); i++){
    if(l1[i].x != l2[i].x || l1[i].y != l2[i].y){
      flag = false;
      break;
    }
  }
  if(flag) return true;
  // 180 度回転
  flag = true;
  kaiten(l2);
  for(int i = 0; i < l1.size(); i++){
    if(l1[i].x != l2[i].x || l1[i].y != l2[i].y){
      flag = false;
      break;
    }
  }
  if(flag) return true;
  // 270 度回転
  flag = true;
  kaiten(l2);
  for(int i = 0; i < l1.size(); i++){
    if(l1[i].x != l2[i].x || l1[i].y != l2[i].y){
      flag = false;
      break;
    }
  }
  if(flag) return true;
  // 360 度回転
  flag = true;
  kaiten(l2);
  for(int i = 0; i < l1.size(); i++){
    if(l1[i].x != l2[i].x || l1[i].y != l2[i].y){
      flag = false;
      break;
    }
  }
  if(flag) return true;

  return false;
}

void init(){
  for(int i = 0; i < MAXC; i++) lines[i].clear();
}

int main(void){

  while(cin >> N, N){
    // Input
    init();
    for(int i = 0; i <= N; i++){
      cin >> M[i];
      for(int j = 0; j < M[i]; j++){
        int x, y;
        cin >> x >> y;
        lines[i].pb((Point){x,y});
      }
    }
    // Equal?
    // 最初の図形は原点にずらしておく
    zurasu(lines[0]);
    for(int i = 1; i <= N; i++){
      // 最初の図形と比較
      // 頂点数が違ったらスルー
      if(lines[0].size() != lines[i].size()) continue;
      // 原点にずらしてから比較
      zurasu(lines[i]);
      if(eq(lines[0], lines[i])) cout << i << endl;
    }
    cout << "+++++" << endl;
  }

}

