#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end

int N;

int main(void){

  cin >> N;
  long long n = 1, i;
  for(i =0; n < N; i++) n *= 3;

  cout << i << endl;

  return 0;
}
