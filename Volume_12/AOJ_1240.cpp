#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

string J(string str){
  str = str[str.size()-1] + str.substr(0,str.size()-1);
  return str;
}

string C(string str){
  str = str.substr(1,str.size()-1) + str[0];
  return str;
}

string E(string str){
  string first;
  string middle;
  string second;

  if(str.size() % 2 == 0){ //文字数が偶数の時
    first = str.substr(0,str.size()/2);
    second = str.substr(str.size()/2);
  
    return second+first;
  }else{ //奇数の時
    first = str.substr(0,str.size()/2);
    middle = str[str.size()/2];
    second = str.substr(str.size()/2+1);
  
    return second+middle+first;
  }
}

string A(string str){
  reverse(str.begin(), str.end());
  
  return str;
}

string P(string str){
  for(int i = 0; i < str.size(); i++){
    if('0' <= str[i] && str[i] <= '9'){
      if(str[i] == '0') str[i] = '9';
      else str[i] -= 1;
    }
  }
  return str;
}

string M(string str){
  for(int i = 0; i < str.size(); i++){
    if('0' <= str[i] && str[i] <= '9'){
      if(str[i] == '9') str[i] = '0';
      else str[i] += 1;
    }
  }
  return str;
}

int main(void){

  int N;
  cin >> N;
  while(N--){
    string order;
    string ans;
    cin >> order;
    cin >> ans;
    reverse(order.begin(),order.end());
    for(int i = 0; i < order.size(); i++){
      switch(order[i]){
        case 'J':
          ans = J(ans);
          break;
        case 'C':
          ans = C(ans);
          break;
        case 'E':
          ans = E(ans);
          break;
        case 'A':
          ans = A(ans);
          break;
        case 'P':
          ans = P(ans);
          break;
        case 'M':
          ans = M(ans);
          break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
