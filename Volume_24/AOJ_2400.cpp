#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

struct ICPC{
  int id, solve, penalty;

  bool operator < (ICPC s) const{
    if(penalty==s.penalty && solve == s.solve) return id < s.id;
    else if(solve==s.solve) return penalty < s.penalty;
    else return solve > s.solve;
  }
};

ICPC icpc[51];
int table[51][11]; //チーム、問題番号

void init(){
  fill((int *)table,(int *)table+51*11,0);

  rep(i,51){
    icpc[i].id = i+1;
    icpc[i].solve = 0;
    icpc[i].penalty = 0;
  }
}

int main(){
  int team, problem, record;
  while(cin >> team >> problem >> record, team || problem){
    init();
    while(record--){
      int tID, pID, time;
      string msg;
      cin >> tID >> pID >> time >> msg;

      if(msg == "CORRECT"){ //AC
        icpc[tID-1].solve++;
        icpc[tID-1].penalty += time + 1200 * table[tID][pID];
      }else{ //WA
        table[tID][pID]++; //問題に対する試行数
      }
    }

    sort(icpc, icpc+team);

    rep(i,team){
      cout << icpc[i].id << " " << icpc[i].solve << " " << icpc[i].penalty << endl;
    }
  }
  return 0;
}
