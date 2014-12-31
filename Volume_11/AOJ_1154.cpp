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

int main(void){

  int n;
  while(cin >> n, n != 1){
    bool isMSP[300001];
    fill(isMSP, isMSP+300001, true);

    cout << n << ":";
    for(int i = 2; i <= n; i++){
      //月曜土曜数だったら処理する
      if(i % 7 == 1 || i % 7 == 6){

        if(isMSP[i]){
          // 素因数である
          if(n % i == 0) cout << " " << i;

          // エラトステネスのふるいにかけていく
          for(int j = i*2; j <= n; j += i){
            isMSP[j] = false;
          }
        }
      }
    }
    cout << endl;
  }
  return 0;
}
