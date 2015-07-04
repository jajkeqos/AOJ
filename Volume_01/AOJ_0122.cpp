#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

const int flog_dx[] = {-2, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 2};
const int flog_dy[] = {-1, 0, 1, -2, 2, -2, 2, -2, 2, -1, 0, 1};
const int sprin_dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int sprin_dy[] = {1, 0, -1, 1, 0, -1, 1, 0, -1};
int flogX;
int flogY;
int sprinX[10];
int sprinY[10];
int sprinN;
bool flag;

void dfs(int x, int y, int now) {
  rep(i, 12) {
    int nx = x + flog_dx[i];
    int ny = y + flog_dy[i];
    if (nx < 0 || 9 < nx || ny < 0 || 9 < ny) continue;
    // 水がかかるかどうか
    rep(j, 9) {
      if (nx == sprinX[now] + sprin_dx[j] && ny == sprinY[now] + sprin_dy[j]) {
        if (now + 1 == sprinN) {
          flag = true;
          break;
        }
        dfs(nx, ny, now + 1);
      }
    }
  }
}

int main(void) {
  while (1) {
    cin >> flogX >> flogY;
    if (flogX == 0 && flogY == 0) break;
    cin >> sprinN;
    rep(i, sprinN) { cin >> sprinX[i] >> sprinY[i]; }
    flag = false;
    dfs(flogX, flogY, 0);

    cout << (flag ? "OK" : "NA") << endl;
  }

  return 0;
}
