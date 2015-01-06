///////////////
// AOJ_2300 //
/////////////

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()
#define MAX_N 21



int N,M;
double L[MAX_N],a[MAX_N],b[MAX_N];
double ans;

double distance(int A, int B){
  double x = L[A] - L[B];
  double y = a[A] - a[B];
  double z = b[A] - b[B];

  return x*x + y*y + z*z;
}

void dfs(int now, int cnt,vector<int> v){

  // M個の要素を選んだ
  if(cnt == M){
    double sum = 0.0;
    rep(i,v.size()) rep(j,v.size()){
      // 選んだM個の距離の総和を取る
      sum += distance(v[i],v[j]);
    }
    ans = max(ans, sum/2.0);
    return;
  }

  if(now == N) return;
  dfs(now+1,cnt,v);
  v.pb(now);
  dfs(now+1,cnt+1,v);

}

int main(void){

  cin >> N >> M;
  rep(i,N){
    cin >> L[i] >> a[i] >> b[i];
  }

  ans = 0.0;

  vector<int> vec;
  dfs(0,0,vec);
  printf("%.7f\n", ans);

  return 0;
}
