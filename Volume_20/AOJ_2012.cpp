#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main(){

  int e;
  while(cin >> e, e){
    int m = INT_MAX/3;
    for(int z = 0; pow(z,3) <= e; z++){
      int t = sqrt(e - pow(z,3));
      int E = e - pow(z,3) - pow(t,2) + t + z;
      m = E < m ? E : m;
    }
    cout << m << endl;
  }
  return 0;
}
