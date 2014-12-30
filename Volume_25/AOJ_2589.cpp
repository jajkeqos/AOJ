#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define inf INT_MAX/4 

int gcd(int a, int b) {return a == 0 ? b : gcd(b%a,a);}

int main(void){
  string str;
  while(cin >> str){
    if(str == "#") break;
    vector<string> v;
    while(1){
      if(str[0] == 'n'){
        v.pb("n");
        str = str.substr(5,str.size()-5);
      }else{
        v.pb("w");
        str = str.substr(4,str.size()-4);
      }
      if(str.size() == 0) break;
    }
    reverse(v.begin(), v.end());

    int ans1 = v[0] == "n" ? 0 : 90;
    int ans2 = 1;

    for(int i = 1; i < v.size(); i++){
      if(v[i] == "n"){ //北
        ans1 = 2 * ans1 - 90;
      }else{ //西
        ans1 = 2 * ans1 + 90;
      }
      ans2 *= 2;
    }

    int dv = gcd(ans1, ans2);
    cout << ans1 / dv;
    if(ans2/dv != 1) cout << "/" << ans2 / dv;
    cout << endl;
    // rep(i,v.size()) cout << v[i];
    // cout << endl;
  }

  return 0;
}
