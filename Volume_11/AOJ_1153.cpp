#include<iostream>
using namespace std;
int taro_n,hanako_n;
int taro[101],hanako[101];
int taro_sum,hanako_sum;
int x,y;

void init(){
  taro_sum = 0;
  hanako_sum = 0;
  x = 999;
  y = 999;
}

int main(void){
  while(1){
  cin >> taro_n >> hanako_n;
  if(taro_n == 0 && hanako_n == 0) break;
  init();
  for(int i = 0; i < taro_n; i++){
    cin >> taro[i];
    taro_sum += taro[i];
  }
  for(int i = 0; i < hanako_n; i++){
    cin >> hanako[i];
    hanako_sum += hanako[i];
  }

  //交換する
  for(int i = 0; i < taro_n; i++){
    for(int j = 0; j < hanako_n; j++){
      int after_taro_sum = taro_sum-taro[i]+hanako[j];
      int after_hanako_sum = hanako_sum-hanako[j]+taro[i];
      //cout << "Taro: " << after_taro_sum << " Hanako: " << after_hanako_sum << endl;
      //cout << "Taro_num " << taro[i] << " Hanako_num: " << hanako[j] << endl;
      if(after_taro_sum == after_hanako_sum && taro[i] + hanako[j] < x+y ){
        x = taro[i];
        y = hanako[j];
      }
    }
  }
  //cout << "x: " << x << " y: " << y << endl;
  if(x != 999 && y != 999){
    cout << x << ' ' << y << endl;
  }else{
    cout << "-1" << endl;
  }
}
  return 0;
}
