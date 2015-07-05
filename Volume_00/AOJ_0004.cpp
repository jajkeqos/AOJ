#include <bits/stdc++.h>
using namespace std;

int main(void) {
  double x1, x2, y1, y2, X, Y;

  while (cin >> x1 >> y1 >> X >> x2 >> y2 >> Y) {
    double det = 1.0 / (x1 * y2 - x2 * y1);
    double ansX = det * (y2 * X - y1 * Y);
    double ansY = det * (x1 * Y - x2 * X);

    if (ansX == 0) ansX = abs(ansX);
    if (ansY == 0) ansY = abs(ansY);

    printf("%.3f %.3f\n", ansX, ansY);
  }

  return 0;
}
