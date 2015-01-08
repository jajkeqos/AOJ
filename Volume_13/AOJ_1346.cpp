#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back 
#define inf INT_MAX/4 
#define ALL(v) v.begin(),v.end()

int unrule(string str){
  int ans = str[0] - '0';
  for(int i = 1; i < str.size(); i+=2){
    if(str[i] == '+') ans += str[i+1] - '0';
    if(str[i] == '*') ans *= str[i+1] - '0';
  }
  return ans;
}

int rule(string str){
  stack<int> st;
  st.push(str[0]-'0');
  for(int i = 1; i < str.size(); i+=2){
    if(str[i] == '+') st.push(str[i+1]-'0');
    if(str[i] == '*') st.top() *= str[i+1]-'0';
  }

  int ans = 0;
  while(!st.empty()){
    ans += st.top(); st.pop();
  }

  return ans;
}

int main(void){
  string str;
  cin >> str;
  int ANS;
  cin >> ANS;

  int ans1 = rule(str);
  int ans2 = unrule(str);

  if(ANS == ans1 && ANS == ans2) cout << "U" << endl;
  else if(ANS == ans1) cout << "M" << endl;
  else if(ANS == ans2) cout << "L" << endl;
  else cout << "I" << endl;



  return 0;
}
