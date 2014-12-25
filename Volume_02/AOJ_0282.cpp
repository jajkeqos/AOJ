//
// Timeを足す対民具
//

#include <bits/stdc++.h>
using namespace std;

struct Point {
  int x,y;
  bool operator < ( const Point& p ) const {
    if( y != p.y ) return y < p.y;
    return x < p.x;
  }
};

int totalTime[100003],totalPoint[100003];
int beforeTime=0,intervalTime=0;


void searchMax(void){
  int max= totalTime[1];
  int maxP=1;
  for(int i = 0; i < 100003; i++){
    if(totalTime[i] > max){
      max = totalTime[i];
      maxP = i;
    }
  }
  cout  <<  maxP << endl;
}


int main(void){
  priority_queue<Point> pq;
  int N,R,L;

  for(int i = 0; i < 100003; i++){
    totalTime[i] = 0;
    totalPoint[i] = 0;
  }

  cin >> N >> R >> L;
  for(int i = 0; i < R; i++){
    int d,t,x;
    cin >> d >> t >> x; //d:TeamID , t:Time , x:Point
    totalPoint[d] += x;
    Point tmp = {d,totalPoint[d]};
    //時間をいままでのに加える処理
    int teamID;
    if(i == 0){
      pq.push(tmp);
      beforeTime = t;
    }else{
      //写った秒数を加える
      teamID = pq.top().x;
      intervalTime = t - beforeTime;
      totalTime[teamID] += intervalTime;
      cout << "i = " << i << " " <<  teamID << "'s Time += " << intervalTime << endl;
      pq.push(tmp);
      while(1){ //古い情報は取り除く
        if(pq.top().y != totalPoint[pq.top().x] && pq.empty() == false){ pq.pop(); cout << "Poped ! " << endl;}
        else break;
      }
      beforeTime = t;
    }
    teamID = d;
    cout << endl;
    cout << "Team: " << teamID << " Point: " << pq.top().y << " Time: " << totalTime[teamID];
  }

  intervalTime = L - beforeTime;
  int teamID = pq.top().x;
  totalTime[teamID] += intervalTime;
  /*  デバッグ用
     cout << endl << endl;
     while(pq.empty() == false){
     cout << "Team: " << pq.top().x << " Point: " << pq.top().y << " Time: " << totalTime[pq.top().x] << endl;
     pq.pop();
     }
  */
  searchMax();

  return 0;

}
