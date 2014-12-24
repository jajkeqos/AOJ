#include <iostream>
using namespace std;

int houseki;
int map[30][30];
int order;
int now_x,now_y,cnt;
void init(void){
  houseki = 0;
  now_x = 10;
  now_y = 10;
  cnt = 0;
  for(int i = 0; i < 30; i++){
    for(int j = 0; j < 30; j++){
      map[i][j] = 0;
    }
  }
}

int main(void){
  while(1){
    init();
    cin >> houseki;
    if(houseki == 0) break;
    for(int i = 0; i < houseki; i++){
      int x,y;
      cin >> x >> y;
      map[x][y] = 1;
    }
    cin >> order;
    for(int i = 0; i < order; i++){
      char hougaku;
      int l;
      cin >> hougaku >> l;
      if(hougaku == 'N'){
        for(int i = 0; i < l; i++){
          now_y++;
          if(map[now_x][now_y] == 1){cnt++;map[now_x][now_y]=0;}
          }
        }else if(hougaku == 'E'){
          for(int i = 0; i < l; i++){
            now_x++;
            if(map[now_x][now_y] == 1){cnt++;map[now_x][now_y]=0;}
            }
          }else if(hougaku == 'S'){
            for(int i = 0; i < l; i++){
              now_y--;
              if(map[now_x][now_y] == 1){cnt++;map[now_x][now_y]=0;}
              }
            }else if(hougaku == 'W'){
              for(int i = 0; i < l; i++){
                now_x--;
                if(map[now_x][now_y] == 1){cnt++;map[now_x][now_y]=0;}
                }
              }
              //cout << "x: " << now_x << " y: " << now_y << endl;
            }
            if(cnt == houseki) cout << "Yes" << endl;
            else cout << "No" << endl;
          }
          return 0;
        }
