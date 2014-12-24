#include <iostream>
#include <utility>
using namespace std;

int tax(double x, double p){ //x=消費税率, p=税抜き価格

  p = (p*(100+x))/(100);

  return p;
}

int main(void){
  int x,y,s,result;

  while(1){
  cin >> x >> y >> s;
  if( x == 0 && y == 0 && s == 0) break;
  result = 0;
  for(int i = 1; i < s; i++){
    for(int j = s-1; j > 0; j--){
      if(tax(x,i) + tax(x,j) == s){
	result = max(tax(y,i) + tax(y,j),result);
      }
    }
  }

  cout << result << endl;
  }
  return 0;
}
