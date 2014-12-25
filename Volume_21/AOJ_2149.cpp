#include <iostream>
using namespace std;

int slot[10001];
int n, a, b, c, x,frame;

void init(){
  for(int i = 0;i < 10001; i++){
    slot[i] = 0;
  }
  frame = 0;
}

int main(){

    while(cin >> n, n){
      init();
      cin >> a >> b >> c >> x;
      for(int i = 0; i < n; i++){
        cin >> slot[i];
      }
      for(int i = 0; i < n;){
        if(x == slot[i]){
          i++;
          if(i == n) break;
        }
        x = (a * x + b) % c;
        frame++;
        if(frame > 10000){frame = -1; break;}
      }
      cout << frame << endl;
    }
  return 0;
}
