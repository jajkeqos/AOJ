#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define INF INT_MAX/3

int N;

int main(void){

  cin >> N;
  while(N--){
    string str;
    cin >> str;
    set<string> s;
    for(int i = 1; i < str.size(); i++){
      string s1, s2, rs1, rs2;  //r付きはreverse
      s1 = rs1 = str.substr(0,i); //substrの第二引数は長さ
      s2 = rs2 = str.substr(i,str.size()-1);
      //reverse
      reverse(rs1.begin(), rs1.end());
      reverse(rs2.begin(), rs2.end());
      //全通り試す
      s.insert(s1+s2);
      s.insert(s2+s1);
      s.insert(rs1+s2);
      s.insert(s2+rs1);
      s.insert(rs2+s1);
      s.insert(s1+rs2);
      s.insert(rs1+rs2);
      s.insert(rs2+rs1);
    }
    cout << s.size() << endl;
  }
  return 0;
}
