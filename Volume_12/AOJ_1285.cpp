#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),b.end()

int main(void){

  int n,w;

  while(cin >> n >> w, n||w){
    int N = 0;
    double d = 0;
    double p[11] = {0};
    double res = 0;
    while(n--){
      int v;
      cin >> v;
      p[v/w]++;
      N = max(N,v/w);
      d = max(d,p[v/w]);
    }
  
    rep(i,N){
      res += ((double)(N-i)/(double)N)*(double)(p[i]/d);
    }

    printf("%.7f\n", res+0.01);
  
  }


  return 0;
}
