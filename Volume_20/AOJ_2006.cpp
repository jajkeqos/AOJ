#include <iostream>
#include <string>
using namespace std;

int N;
string btn[10] = {"",".,!? ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int main(void){

  cin >> N;
  while(N--){
    string str;
    cin >> str;
    int charType,cnt;
    charType = cnt = 0;
    for(int i = 0; i < str.size(); i++){
      int charNow = str[i] - '0'; //char to INT
      if(charNow == 0){
        if(charType != 0) cout << btn[charType][(cnt-1)%btn[charType].size()];
        charType = cnt = 0;
      }else{
        charType = charNow;
        cnt++;
      }
    }
    cout << endl;
  }
  return 0;
}
