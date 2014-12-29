#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

const string station = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

char solve(char st, int key){
  //今の駅の添字を取得する
  int pos = station.find(st);
  //暗号を解く
  pos -= key;
  if(pos < 0){ //posがマイナスだったとき
    pos = station.find(st);
    key -= pos;
    pos = station.size() - key;
  }

  return station[pos];
}

int main(){

  int n;

  while(cin >> n,n){
    vector<int> v;
    while(n--){
      int tmp;
      cin >> tmp;
      v.push_back(tmp);
    }
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++){
      char now = str[i];
      int key = v[i%v.size()];
      //cout << "now: " << now << " " << "key: " << key << endl;
      cout << solve(now,key);
    }
    cout << endl;
  }
  return 0;
}
