#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

int main(){
  int n;
  int N;
  cin >> N;
  while(N--){
    int cnt = 0;
    cin >> n;
    string str_n = to_string(n); //string型に入力を変換
    while(1){
      if(str_n.size() == 1){ //1桁だったら終了する
        cout << cnt << endl;
        break;
      }else{
        int nMax = 0;
        for(int i = 1;i < str_n.size(); i++){
          int first = stoi(str_n.substr(0,i));
          int second = stoi(str_n.substr(i));
          //cout << "First: " << first << " Second: " << second << endl;
          nMax = max(nMax,first*second);
        }
        str_n = to_string(nMax);
        cnt++;
      }
    }
  }

  return 0;
}
