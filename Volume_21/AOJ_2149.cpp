#include <iostream>
using namespace std;

int y,frame;

void init(){
  frame = 0;
}

int main(void){

  int  N, A, B, C, X;

  while(cin >> N >> A >> B >> C >> X && N){
    init();
    int x = X;
    bool first = true;
    for(int i = 0; i < N; i++){
      cin >> y;
      while(frame <= 10000){
        if(first && y == X) break;
        frame++;
        x = (A * x + B) % C;
        if(y == x) break;
        //cout << i << ' ' << "x: " << x << endl;
        first = false;
      }
    }
    if(frame == 10001) frame = -1;
    cout << frame << endl;
  }

  return 0;
}
