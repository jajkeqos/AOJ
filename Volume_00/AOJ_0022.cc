#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()

int cSum[5001];
int n[5001];
int mx;

void init(void){
  n[0] = 0;
  mx = -inf;
}

int main(void){

  int N;
  while(cin >> N){
    if(N == 0) break;
    init();
    Rep(i,N+1) cin >> n[i];
    Rep(i,N+1) cSum[i] = n[i] + cSum[i-1];
    //rep(i,N+1) cout << cSum[i] << endl;
    for(int i = 0; i < N; i++){
      for(int j = i + 1; j < N+1; j++){
        mx = max(mx,cSum[j] - cSum[i]);
      }
    }
    cout << mx << endl;
  }



  return 0;
}
