#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main(void){
  string str;
  string kakko="([)]";
  while(getline(cin,str), str != "."){ //空白が入っているのでgetline
    stack<int> s;
    bool flag = true;
    for(int i = 0; i < str.size(); i++){
      for(int j = 0; j <= 1; j++){
        if(str[i] == kakko[j]) s.push(j); //開きカッコが現れた時
        if(str[i] == kakko[j+2]){ //閉じカッコが現れた時
          if(s.empty() || j != s.top()) flag = false; //対応するカッコがなかったときはフラグを折る
          else s.pop(); //対応していたらそれをポップする
        }
      }
    }
    cout << (flag&&s.empty() ? "yes" : "no")<< endl;
  }
  return 0;
}
