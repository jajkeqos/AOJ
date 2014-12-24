#include <iostream>
#include <string>
using namespace std;

int main(){
  string str;
  const string left = "qwertasdfgzxcvb";
  int cnt;
  int now;
  while(cin >> str, str != "#"){
    cnt = 0;
    now = -1; //left: 0 , right: 1
    for(int i = 0; i < str.size(); i++){
      if(left.find(str[i]) != string::npos){ //左側にあるとき
          if(now == -1 || now == 0) {now = 0;}
          else {now = 0; cnt++;}
      }else{ //右側にあるとき
          if(now == -1 || now == 1) {now = 1;}
          else {now = 1; cnt++;}
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
