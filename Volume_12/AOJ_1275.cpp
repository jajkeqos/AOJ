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

int j(int n, int k){
  if(n == 1) return 0;
  
  return (j(n-1,k)+k) % n;
}

int main(void){

  int n,m,k;
  
  while(cin >> n >> k >> m, n||m||k){
    m = (m - k + 1 + n) % n;
  
    cout << (j(n,k)+m-1+n)%n+1 << endl;
  }

  return 0;
}
