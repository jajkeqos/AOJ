#include <iostream>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()


int dp[50];

int fib(int n){
  if(n == 0 || n == 1) return dp[n] = 1; 
  if(dp[n] != -1) return dp[n];

  return dp[n] = fib(n-1) + fib(n-2);
}

int main(void){

  int n;

  cin >> n;

  rep(i,50) dp[i] = -1;

  cout << fib(n) << endl;

  return 0;
}
