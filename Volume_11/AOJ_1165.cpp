#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //左、下、右、上
typedef pair<int, int> P;
vector<P> v;

int main(){

  int N;
  int xmax, ymax;
  int xmin, ymin;

  while(cin >> N, N){
    xmax = ymax = 0;
    xmin = ymin = 0;
    v = vector<P>(N);
    v[0] = P(0,0);
    for(int i = 1; i < N; i++){
      // cout << "i: " << i << endl;
      int n,d;
      cin >> n >> d;
      v[i] = P(v[n].first + dx[d], v[n].second + dy[d]);
      xmax = max(xmax, v[i].first);
      xmin = min(xmin, v[i].first);
      ymax = max(ymax, v[i].second);
      ymin = min(ymin, v[i].second);
    }
    cout << xmax - xmin + 1 << ' ' << ymax - ymin + 1 << endl;
  }
  return 0;
}
