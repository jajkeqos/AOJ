#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()

static const double EPS = 1e-9;
static const int MOD = 256;

int I[256];
int R[256];
int O[256];


int main(void){

  int N;

  while(cin >> N, N){
  
    // 入力
    for(int i = 1; i <= N; i++){
      cin >> I[i];
    }
  
  
    int ansS, ansA, ansC;
    double ansH = 100000000.0;

    // S,A,Cを全通り試す
    for(int s = 0; s <= 15; s++){
      for(int a = 0; a <= 15; a++){
        for(int c = 0; c <= 15; c++){

          double H = 0.0;
          R[0] = s;
          fill(O,O+256,0);

          for(int i = 1; i <= N; i++){
            R[i] = (a*R[i-1]+c)%MOD;
            O[(I[i]+R[i])%MOD]++;
          }

          // Hの計算式通り
          for(int i = 0; i < 256; i++){
            if(O[i] != 0) H -= (O[i]/(double)(N)*log(O[i]/(double)(N)));
          }

          // Hが最小だったら更新する
          if(H+EPS<ansH){
            ansH = H;
            ansS = s;
            ansA = a;
            ansC = c;
          }
        }
      }
    }
    cout << ansS << " " << ansA << " " << ansC << endl;
  }


  return 0;
}
