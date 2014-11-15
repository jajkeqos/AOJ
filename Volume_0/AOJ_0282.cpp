//
// Timeを足す対民具
//




#include <bits/stdc++.h>
#include <iostream>
#include <queue>
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
    pq.push(tmp);

    int teamID = pq.top().x;

    if(i == 0){

    }else{
      //写った秒数を加える
      intervalTime = t - beforeTime;
      totalTime[teamID] += intervalTime;
    }
    beforeTime = t;
    cout << endl;
    cout << "Team: " << teamID << " Point: " << pq.top().y << " Time: " << totalTime[teamID];
  }
  cout << endl;
  
  intervalTime = L - beforeTime;
  int teamID = pq.top().x;
  totalTime[teamID] += intervalTime;

  searchMax();

  return 0;

}
