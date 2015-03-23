#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX 
#define ALL(v) v.begin(),v.end()

int main(void){

  int maxP = -inf;
  int minP = inf;

  int n;

  cin >> n;

  cin >> minP;

  rep(i,n-1){
    int tmp;
    cin >> tmp;
    maxP = max(maxP,tmp-minP);
    minP = min(minP, tmp);
  }

  cout << maxP << endl;


  return 0;
}
