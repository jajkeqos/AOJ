#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;
typedef string::const_iterator State;
class ParseError{};

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define inf INT_MAX/4
#define ALL(v) v.begin(),v.end()


int number(State &begin);
int factor(State &begin);
int expression(State &begin);
int term(State &begin);

void consume(State &begin, char expected) {
    if (*begin == expected) {
        begin++;
    } else {
        cerr << "Expected '" << expected << "' but got '" << *begin << "'"
            << endl;
        cerr << "Rest string is '";
        while (*begin) {
            cerr << *begin++;
        }
        cerr << "'" << endl;
        throw ParseError();
    }
}


// 数字をパースする
int number(State &begin){
  int ret = 0;

  while(isdigit(*begin)){
    ret *= 10;
    ret += *begin - '0';
    begin++;
  }

  return ret;
}

// カッコか数をパースして結果を返す
int factor(State &begin){
  if(*begin == '('){
    begin++;
    int ret = expression(begin);
    consume(begin, ')');
    return ret;
  }else{
    return number(begin);
  }

}
// 四則演算の式をパースして評価結果を返す
int expression(State &begin){
  int ret = term(begin);

  while(1){
    if(*begin == '+'){
      begin++;
      ret += term(begin);
    }else if(*begin == '-'){
      begin++;
      ret -= term(begin);
    }else{
      break;
    }
  }

  return ret;
}



// 乗算除算の式をパースして評価結果を返す
int term(State &begin){
  int ret = factor(begin);

  while(1){

    if(*begin == '*'){
      begin++;
      ret *= factor(begin);
    }else if(*begin == '/'){
      begin++;
      ret /= factor(begin);
    }else{
      break;
    }
  }

  return ret;
}


int main(void){
  int N;
  cin >> N;
  cin.ignore();

  rep(i,N){
    string s;
    getline(cin,s);

    State begin = s.begin();

    int ans = expression(begin);
    consume(begin, '=');

    cout << ans << endl;

  }

  return 0;
}
