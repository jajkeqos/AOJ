#include <iostream>
#include <string>
using namespace std;

int n;
string mcxi[2];


int main(){

  cin >> n;
  while(n--){
    int num[2] = {0};
    cin >> mcxi[0] >> mcxi[1];

    // mcxi => 10
    for(int i = 0; i < 2; i++){ //入力が２つある
      for(int j = 0; j < mcxi[i].size(); j++){ //文字をひとつづつ見ていく
        string s = mcxi[i];
        if('0' < s[j] && s[j] <= '9'){ //数字の時
          // cout << "s[" << j << "]: "<< s[j] << endl;
          // cout << "s[" << j << "]: "<< s[j+1] << endl;
          if(s[j+1] == 'm') num[i] += (s[j] - '0') * 1000;
          else if(s[j+1] == 'c') num[i] += (s[j] - '0') * 100;
          else if(s[j+1] == 'x') num[i] += (s[j] - '0') * 10;
          else if(s[j+1] == 'i') num[i] += (s[j] - '0') * 1;
          j++;
        }else{
          // cout << "ns[" << j << "]: "<< s[j] << endl;
          if(s[j] == 'm') num[i] += 1000;
          else if(s[j] == 'c') num[i] += 100;
          else if(s[j] == 'x') num[i] += 10;
          else if(s[j] == 'i') num[i] += 1;
        }
      }
    }
    int ans = num[0] + num[1];
    // cout << "num[0]: " << num[0] << " num[1]: " << num[1] << endl;
    // cout << "ans: "<< ans << endl;

    // 10 => mcxi
    while(ans > 0){
      if(ans / 1000 > 0){ //1000以上のとき
        int m = ans / 1000;
        ans = ans - (m * 1000);
        if(m == 1) cout << "m";
        else cout << m << "m";
      }else if(ans / 100 > 0){ //100以上のとき
        int c = ans / 100;
        ans = ans - (c * 100);
        if(c == 1) cout << "c";
        else cout << c << "c";
      }else if(ans / 10 > 0){ //10以上のとき
        int x = ans / 10;
        ans = ans - (x * 10);
        if(x == 1) cout << "x";
        else cout << x << "x";
      }else{
        if(ans == 1){
          cout << "i";
        }else{
          cout << ans << "i";
        }
        break;
      }
    }
    cout << endl;
  }
  return 0;
}
