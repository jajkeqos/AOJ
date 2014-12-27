#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[1000000];

string fillZero(string s, int l){
  if(s.size() == l){
    return s;
  }else{
    return fillZero("0"+s,l);
  }
}

int main(void){
  string A;
  int l;

  while(cin >> A >> l, l){
    fill(a, a+1000000, -1);

    for(int i = 0; i <= 20; i++){ //20は超えない
      if(a[stoi(A)] >= 0){
        cout << a[stoi(A)] << " " << A << " " << i - a[stoi(A)] << endl;
        break;
      }

      a[stoi(A)] = i; //訪れる

      A = fillZero(A,l); //0で満たす
      //次のAを生成する
      sort(A.begin(), A.end());
      // cout << "sort: " << A << endl;
      string max = string(A.rbegin(), A.rend());
      // cout << "max: " << max << endl;
      string min = string(A.begin(), A.end());
      // cout << "min: " << min << endl;
      A = to_string(stoi(max) - stoi(min)); //intに変換して差を求めてそれをstrにする
    }
  }
  return 0;
}
