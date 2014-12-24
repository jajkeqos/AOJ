#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<string> registerID;
bool door = false; //false:閉, true:開

int main(){

cin >> N;

while(N--){ //regist ID
  string str;
  cin >> str;
  registerID.push_back(str);
}

cin >> M;

while(M--){
  string str;
  cin >> str;
  vector<string>::iterator strFind = find(registerID.begin(), registerID.end(), str);
  if(strFind != registerID.end()){ //Find
    if(door){ //open
      cout << "Closed by " << str << endl;
      door = false;
    }else{ //close
      cout << "Opened by " << str << endl;
      door = true;
    }
  }else{
    cout << "Unknown " << str << endl;
  }
}
  return 0;
}
