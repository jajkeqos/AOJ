#include <iostream>
#include <string>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()
#define N 1001

int c[N][N];

int lcs(string X, string Y){
  int lx = X.size();
  int ly = Y.size();
  int ans = 0;

  X = ' ' + X;
  Y = ' ' + Y;

  rep(i,lx) rep(j,ly) c[i][j] = 0;

  rep(i,lx){
   rep(j,ly){
    if(X[i] == Y[j]){
      c[i][j] = c[i-1][j-1] + 1;
    }else{
      c[i][j] = max(c[i-1][j], c[i][j-1]);
    }
    ans = max(ans, c[i][j]);
   }
  }

  return ans;
}

int main(void){

  int q;

  cin >> q;

  while(q--){
    string X, Y;
    cin >> X >> Y;

    cout << lcs(X, Y) << endl;
  
  }

  return 0;
}
