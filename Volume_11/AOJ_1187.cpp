#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <tuple>
using namespace std;

struct ICPC{
 int tID, ac, time;
 ICPC(int tID, int ac, int time):tID(tID),ac(ac),time(time){}

 bool operator < (const ICPC &right) const{
   if(ac != right.ac) return ac> right.ac;
   if(time != right.time) return time < right.time;
   return tID > right.tID;
 }
};


bool operator == (const ICPC& a, const ICPC& b){
  return tie(a.ac,a.time) == tie(b.ac,b.time);
}


int main(){
  int M, T, P, R;
  while(cin >> M >> T >> P >> R, M||T||P||R){
    vector<ICPC> v;
    int table[60][20];
    fill((int *)table,(int *)table+60*20,0);
    //初期化
    for(int i = 0;i < T; i++) v.push_back(ICPC(i+1,0,0)); 
  
    while(R--){
      int m, t, p, j;
      cin >> m >> t >> p >> j;

      if(!j){ //ACのとき
        v[t-1].ac++;
        v[t-1].time += m + 20 * table[t-1][p];
      }else{ //WAのとき
        table[t-1][p]++;
      }
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < T; i++){
      //最後だったらなにも出力せず、順位が同じだったら=それ以外だったら,を出力する
      cout << v[i].tID << ((i == T-1) ? "" : (v[i] == v[i+1]) ? "=" : ",");
    }
    cout << endl;
  }
  return 0;
}
